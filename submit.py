#!/usr/bin/env python
import argparse
import subprocess as sp
import json
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


def make_red(string):
  return f"\033[1;30;41m {string} \033[0;0m"


def make_green(string):
  return f"\033[1;30;42m {string} \033[0;0m"


def make_yellow(string):
  return f"\033[1;30;43m {string} \033[0;0m"


def make_blue(string):
  return f"\033[1;30;44m {string} \033[0;0m"


def make_sky_blue(string):
  return f"\033[1;30;46m {string} \033[0;0m"


def print_with_empty_line(string):
  print(string, end="\n\n")


def get_int(string):
  res = "invalid string"
  while not res.isdigit():
    res = input(string)
  return int(res)


def get_test_path(contest, problem_id):
  CODEFORCES_GYM_THRESHOLD = 100000
  place = "gym" if int(contest) >= CODEFORCES_GYM_THRESHOLD else "contest"
  return f".config/data/cf/{place}/{contest}/{problem_id}"


if __name__ == "__main__":
  PATH_TO_CONTEST_FILE = "./.config/path_to_contest.json"
  parser = argparse.ArgumentParser(allow_abbrev=False)
  parser.add_argument("-f", "--file", required=True)
  parser.add_argument("-c", "--contest")
  parser.add_argument("-r", "--run", dest="run", action="store_true")
  parser.add_argument("-s", "--submit", dest="submit", action="store_true")
  parser.add_argument("-e", "--exact", dest="exact", action="store_true")
  parser.add_argument("-o", "--only", dest="only", action="store_true")
  args = parser.parse_args()
  origin_file = os.path.normpath(args.file)
  filename = os.path.normpath(os.path.relpath(args.file))
  contest = args.contest
  abs_cf = os.path.abspath("/usr/bin/cf")

  # fetch contest id, problem id
  if args.only:
    contest = get_int(make_yellow("enter the contest id:") + " ")
    problem_id = input(make_sky_blue("enter the problem id:") + " ")
    print()
  else:
    # special check div2
    if os.path.basename(filename)[0].isdigit():
      directory = os.path.dirname(filename)
      basename = os.path.basename(filename)
      filename = os.path.join(directory, basename[0], basename[1:])
    path = os.path.dirname(filename)

    # parse problem id
    if not args.exact:
      problem_id: str = os.path.basename(filename)[0]
    else:
      problem_id = os.path.splitext(os.path.basename(filename))[0]

    # get contest id
    if not contest:
      if os.path.exists(PATH_TO_CONTEST_FILE):
        with open(PATH_TO_CONTEST_FILE) as f:
          path_to_contest: dict = json.load(f)
      else:
        path_to_contest = {}

      if path in path_to_contest:
        contest = path_to_contest[path]
      else:
        contest = get_int(make_yellow("enter the contest id:") + " ")
        # if next promt is not a query, add an empty line
        test_path = get_test_path(contest, problem_id)
        if not os.path.exists(os.path.dirname(test_path)) or os.path.exists(test_path):
          print()
        # save
        path_to_contest[path] = contest
        os.makedirs(os.path.dirname(PATH_TO_CONTEST_FILE), exist_ok=True)
        with open(PATH_TO_CONTEST_FILE, "w+") as f:
          f.write(json.dumps(path_to_contest, sort_keys=True, indent=2))

  test_path = get_test_path(contest, problem_id)

  # parse samples
  if not os.path.exists(os.path.dirname(test_path)):
    print(cf_cmd := f"{abs_cf} parse {contest}")
    sp.run(cf_cmd, shell=True)
    print()

  # verify probelm id
  if not os.path.exists(test_path):
    problem_id = problem_id[0].upper() + problem_id[1:]
    while not os.path.exists(test_path):
      problem_id = input(make_sky_blue("enter the problem id:") + " ")
      test_path = get_test_path(contest, problem_id)
    print()

  # test sample
  if args.run:
    print_with_empty_line(make_blue("Testing Sample..."))
    with cd(test_path):
      print_with_empty_line(cf_cmd := f"{abs_cf} test {origin_file}")
      p = sp.run(cf_cmd, shell=True, capture_output=True, text=True)
      AC, WA, RE = "AC", "WA", "RE"
      test_result_str = (p.stdout.replace("Passed", make_green(AC))
                         .replace("Runtime Error", make_red(RE))
                         .replace("Failed", make_red(WA)))
      test_result = [x for x in test_result_str.split("\n") if " ... " in x]
      if any(WA in x for x in test_result):
        print(test_result_str)
        if test_result_str[-2:] != "\n\n":
          print()
      cases_cnt = len(test_result)
      failed_cases = [i for i, v in enumerate(test_result) if AC not in v]
      if failed_cases:
        numbers = " ".join([f"#{x + 1}" for x in failed_cases])
        print_with_empty_line(
            make_red(f"FAIL {len(failed_cases)} of {cases_cnt}") + f" {numbers}"
        )
      else:
        print_with_empty_line(make_green(f"PASS {cases_cnt} of {cases_cnt}"))
      # print summary
      print_with_empty_line("\n".join(test_result))
      if args.submit and failed_cases:
        args.submit = False
        print_with_empty_line(make_red("Aborting..."))

  # submit
  if args.submit:
    print_with_empty_line(make_blue("Submitting..."))
    print(cf_cmd := f"{abs_cf} submit -f {origin_file} {contest} {problem_id}")
    sp.run(cf_cmd, shell=True)
