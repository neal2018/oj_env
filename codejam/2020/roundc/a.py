

def solve():
    N, K = map(int, (input()).split(" "))
    P = map(int, (input()).split(" "))
    P = sorted(set(P))
    n = len(P)
    for i in range(n):
        P[i]-=1
    maxi = 0
    def calc(pi, i):
        if pi < 0 or pi > K - 1:
            return 0
        if i == -1:
            return pi + 1
        elif i == n - 1:
            return K - 1 - P[i]
        else:
            return (P[i + 1] - P[i]) // 2

    for i in range(n):
        for j in range(n):
            t1 = P[i] - 1
            t2 = P[j] - 1
            temp = calc(t1, i - 1)
            if t1 != t2:
                temp += calc(t2, j - 1)
            maxi = max(maxi, temp)

            t1 = P[i] + 1
            t2 = P[j] - 1
            temp = calc(t1, i)
            if t1 != t2:
                temp += calc(t2, j - 1)
                if i < n - 1 and i == j - 1 and (P[i + 1] - P[i]) % 2 == 0:
                    temp -= 1
            maxi = max(maxi, temp)

            t1 = P[i] - 1
            t2 = P[j] + 1
            temp = calc(t1, i - 1)
            if t1 != t2:
                temp += calc(t2, j)
                if i > 0 and i - 1 == j and (P[i] - P[i - 1]) % 2 == 0:
                    temp -= 1
            maxi = max(maxi, temp)

            t1 = P[i] + 1
            t2 = P[j] + 1
            temp = calc(t1, i)
            if t1 != t2:
                temp += calc(t2, j)
            maxi = max(maxi, temp)
            # print(maxi)

    return maxi / K


t = int(input())
for i in range(1, t + 1):
    r = solve()
    print(f"Case #{i}: {r:.10f}")
