import random
from random import randint
import sys


def gen_tree(point_num: int, one_based=True):
  res = []
  for i in range(1, point_num):
    u = random.randint(0, i - 1)
    res.append((u, i))
  random.shuffle(res)
  if one_based:
    res = [(u + 1, v + 1) for u, v in res]
  return res


def gen_graph(point_num: int, edge_num: int, one_based=True):
  res = gen_tree(point_num, False)
  used_edges = set(res)
  while len(used_edges) < edge_num:
    u = random.randint(0, point_num)
    v = random.randint(0, point_num)
    if u == v or (u, v) in used_edges:
      continue
    res.append((u, v))
    used_edges.add((u, v))
  random.shuffle(res)
  if one_based:
    res = [(u + 1, v + 1) for u, v in res]
  return res


def gen_str(length, start="a", size=26) -> str:
  string = ""
  for _ in range(length):
    string += chr(ord(start) + random.randint(0, size - 1))
  return string


def gen_str_pool(length, pool) -> str:
  string = ""
  for _ in range(length):
    string += random.choice(pool)
  return string


def gen_array(length, mini=1, maxi=10**9):
  res = []
  for _ in range(length):
    cur = random.randint(mini, maxi)
    res.append(cur)
  return res


def gen_permutation(length, one_based=True):
  res = [i for i in range(length)]
  random.shuffle(res)
  if one_based:
    res = [x + 1 for x in res]
  return res


def gen_l_r(mini, maxi):
  l = random.randint(mini, maxi)
  r = random.randint(mini, maxi)
  if l > r:
    l, r = r, l
  return [l, r]


def gen_sum_array(n: int, s: int):
  if n == 0:
    return []
  pool = [i for i in range(1, s)]
  a = sorted([0] + random.sample(pool, n - 1) + [s])
  return [a[i + 1] - a[i] for i in range(n)]


def gen_sum_array_max(n: int, s: int, maxi: int):
  a = gen_sum_array(n, s)
  total = 0
  for i in range(n):
    if a[i] > maxi:
      total += a[i] - maxi
      a[i] = maxi
  index = [i for i in range(n)]
  random.shuffle(index)
  for i in index:
    minus = min(total, maxi - a[i])
    a[i] += minus
    total -= minus
  return a


def print_array(a, need_len=True, delimiter=" ", end="\n"):
  if need_len:
    print(len(a))
  for i, v in enumerate(a):
    if i != 0:
      print(delimiter, end="")
    print(v, end="")
  print(end, end="")


if __name__ == "__main__":
  print(T := 1)
  N = 8
  print(gen_str(N, 'a', 5))
