import math


n = int(input())
a = list(map(int, input().split(" ")))

freq = {i: 0 for i in range(15)}

for x in a:
  for i in range(15):
    if x & (1 << i):
      freq[i] += 1

res = [0] * n

for k, v in freq.items():
  for i in range(v):
    res[i] |= (1 << k)

mean = sum(res)
var = sum((n * x - mean) ** 2 for x in res)
g = math.gcd(var, n * n * n)

print(f"{var//g}/{(n*n*n)//g}")
