from decimal import *

a, b, c = list(map(int, input().split(" ")))
getcontext().prec = c
res = "{{:.{}f}}".format(c).format(Decimal(a) / Decimal(b))
print(res)
