import random

t = 100
print(t)
for tt in range(t):
  n = random.randint(1, 1000)
  m = random.randint(1, 1000)
  k = random.randint(1, 5)
  print(f"{n} {m} {k}")
  for i in range(m):
    start = random.randint(1, n)
    print(f"{random.randint(1,10)} {start} {random.randint(start,n)}")
