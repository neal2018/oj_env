#!/usr/bin/env python
# https://github.com/sharmaeklavya2/croupier/blob/master/croupier.py

"Cross-connect stdin and stdout of 2 processes and show outputs from each."

import os
import sys
import shlex
import subprocess
import threading
import argparse
from typing import TextIO


class Color:
    PURPLE = "\033[95m"
    CYAN = "\033[96m"
    DARK_CYAN = "\033[36m"
    BLUE = "\033[94m"
    GREEN = "\033[92m"
    YELLOW = "\033[93m"
    RED = "\033[91m"
    BOLD = "\033[1m"
    UNDERLINE = "\033[4m"
    END = "\033[0m"


def parts_to_print_gen(print_buffer: bytearray, parts: list[bytes]):
    yield print_buffer
    for part in parts[1:-1]:
        yield part


def transfer_and_print(
    fd1: int,
    fd2: int,
    name: str = "",
    screen: TextIO | None = None,
    log_file: TextIO | None = None,
):
    "Transfer data from fd1 to fd2 and print to screen and log file"

    print_buffer = bytearray()
    BUFFER_SIZE = 1024
    while True:
        ch = os.read(fd1, BUFFER_SIZE)
        if ch == b"":
            break
        parts = ch.split(b"\n")
        print_buffer += parts[0]
        if len(parts) > 1:
            for part in parts_to_print_gen(print_buffer, parts):
                try:
                    s = part.decode()
                except UnicodeDecodeError:
                    s = str(bytes(part))
                if screen:
                    color = Color.YELLOW if log_file else Color.DARK_CYAN
                    print(f"{color}{name}: {s}{Color.END}" if name else s, file=screen)
                if log_file:
                    print(f"{s}", file=log_file)
            print_buffer = bytearray(parts[-1])
        os.write(fd2, ch)


def logged_pipe(
    name: str = "", screen: TextIO | None = None, log_file: TextIO | None = None
):
    if screen is None and log_file is None:
        return os.pipe()
    else:
        fd1, write_end = os.pipe()
        read_end, fd2 = os.pipe()
        args = (fd1, fd2, name, screen, log_file)
        thread = threading.Thread(target=transfer_and_print, args=args)
        thread.daemon = True
        thread.start()
        return (read_end, write_end)


def interact(
    proc_str1: str,
    proc_str2: str,
    name1: str = "USR",
    name2: str = "GEN",
    screen: TextIO | None = None,
    log_file: TextIO | None = None,
):
    proc_args1 = shlex.split(proc_str1)
    proc_args2 = shlex.split(proc_str2)
    a_to_b = logged_pipe(name1, screen, None)
    b_to_a = logged_pipe(name2, screen, log_file)
    pa = subprocess.Popen(proc_args1, stdin=b_to_a[0], stdout=a_to_b[1])
    pb = subprocess.Popen(proc_args2, stdin=a_to_b[0], stdout=b_to_a[1])
    pa.wait()
    pb.wait()
    if pa.returncode or pb.returncode:
        sys.exit(1)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("proc1", help="Command line of 1st process")
    parser.add_argument("proc2", help="Command line of 2nd process")
    parser.add_argument(
        "-q",
        "--quiet",
        action="store_true",
        default=False,
        help="Don't print output from processes",
    )
    parser.add_argument("--name1", default="USR", help="Name of 1st process")
    parser.add_argument("--name2", default="GEN", help="Name of 2nd process")
    parser.add_argument("--log_file", default="input.txt", help="Name of log file")
    args = parser.parse_args()
    screen = None if args.quiet else sys.stdout

    with open(args.log_file, "w") as f:
        f.write("")
        interact(args.proc1, args.proc2, args.name1, args.name2, screen, f)


if __name__ == "__main__":
    main()
