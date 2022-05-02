#!/usr/bin/env python
import argparse
import subprocess as sp
import json
import pathlib
import os


class cd:
  """Context manager for changing the current working directory"""

  def __init__(self, newPath):
    self.newPath = os.path.expanduser(newPath)

  def __enter__(self):
    self.savedPath = os.getcwd()
    os.chdir(self.newPath)

  def __exit__(self, etype, value, traceback):
    os.chdir(self.savedPath)


def print_red(string):
  print(f"\033[1;30;41m {string} \033[0;0m")

def print_green(string):
  print(f"\033[1;30;42m {string} \033[0;0m")

def print_yellow(string):
  print(f"\033[1;30;44m {string} \033[0;0m")

if __name__ == "__main__":
  PATH_TO_CONTEST_FILE = "./.config/path_to_contest.json"
  parser = argparse.ArgumentParser()
  parser.add_argument("-f", "--file", required=True)
  parser.add_argument("-c", "--contest")
  parser.add_argument("-r" "--run", dest="run", default=True)
  parser.add_argument("-s" "--submit", dest="submit", default=True)
  parser.add_argument("-e" "--exact", dest="exact", default=False)
  args = parser.parse_args()
  origin_file = os.path.normpath(args.file)
  filename = os.path.normpath(os.path.relpath(args.file))
  contest = args.contest

  # special check div2
  if os.path.basename(filename)[0].isdigit():
    directory = os.path.dirname(filename)
    basename = os.path.basename(filename)
    filename = os.path.join(directory, basename[0], basename[1:])
  path = os.path.dirname(filename)

  # get contest id
  if not contest:
    if os.path.exists(PATH_TO_CONTEST_FILE):
      with open(PATH_TO_CONTEST_FILE) as f:
        path_to_contest = json.load(f)
    else:
      path_to_contest = {}

    if path in path_to_contest:
      contest = path_to_contest[path]
    else:
      while True:
        try:
          contest = int(input("enter the contest id: "))
        except BaseException:
          pass
        else:
          break
      path_to_contest[path] = contest
      os.makedirs(os.path.dirname(PATH_TO_CONTEST_FILE), exist_ok=True)
      with open(PATH_TO_CONTEST_FILE, "w+") as f:
        json.dump(path_to_contest, f)

  if not args.exact:
    problem_id = os.path.basename(filename)[0]
  else:
    problem_id = os.path.splitext(os.path.basename(filename))[0]
  abs_cf = os.path.abspath("cf.exe")

  # test sample
  if args.run == True:
    print_yellow("Testing Sample...")
    test_path = f".config/data/cf/contest/{contest}/{problem_id}"
    if not os.path.exists(test_path):
      print(cf_cmd := f"{abs_cf} parse {contest}")
      sp.run(cf_cmd, shell=True)
    with cd(f".config/data/cf/contest/{contest}/{problem_id}"):
      print(cf_cmd := f"{abs_cf} test {origin_file}")
      p = sp.run(cf_cmd, shell=True, capture_output=True, text=True)
      print(p.stdout)
      if "Failed" in p.stdout:
        print_red("Failed Sample, aborting...")
        exit()
      else:
        print_green("Passed Sample")
        print()

  # submit
  if args.submit == True:
    print_yellow("Submitting...")
    print(cf_cmd := f"{abs_cf} submit -f {origin_file} {contest} {problem_id}")
    sp.run(cf_cmd, shell=True)
