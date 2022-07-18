import random


def gen_tree(point_num: int, one_based=True) -> list[tuple[int, int]]:
  res = []
  for i in range(1, point_num):
    u = random.randint(0, i - 1)
    res.append((u, i))
  random.shuffle(res)
  if one_based:
    res = [(u + 1, v + 1) for u, v in res]
  return res


def gen_graph(point_num: int, edge_num: int, one_based=True) -> list[tuple[int, int]]:
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


def gen_array(length, mini=1, maxi=10**9, total=10**18) -> list[int]:
  res = []
  for _ in range(length):
    cur = random.randint(mini, maxi)
    res.append(cur)
  res_total = sum(res)
  if res_total > total:
    res = [x * total // res_total for x in res]
  return res


def gen_permutation(length, one_based=True) -> list[int]:
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


if __name__ == "__main__":
  print(N := 2 * 10 ** 5)
  print(C := 40)
  print(Q := 10**4)
  sz = N
  print(gen_str(N))
  for _ in range(C):
    print(1, sz)
    sz *= 2
  for _ in range(Q):
    print(random.randint(1, sz))
