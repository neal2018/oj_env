import random

print(N := 10)
M = 5
s = set()
for i in range(N):
  t = (random.randint(0, M), random.randint(0, M))
  while t in s:
    t = (random.randint(0, M), random.randint(0, M))
  s.add(t)
  print(t[0], t[1])
