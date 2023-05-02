n, k = map(int, input().split())
print(["LURD" * (n + ~k) + "ULDL" * n + "RDL", "RULD" * k][k < n / 2])
