

def double(s):
    return s + "0"


def nott(s):
    ans = []
    for c in s:
        if c == "1":
            ans.append("0")
        else:
            ans.append("1")
    if "1" in ans:
        ans = ans[ans.index("1"):]
        return "".join(ans)
    else:
        return "0"


def solve():
    s,e = (input()).split(" ")

    seen = set(s)
    q = [s]
    step = 0
    while q:
        # print(q)
        nq = []
        for node in q:
            if node == e:
                return step
            n2 = double(node)
            if len(s) < 30 and n2 not in seen:
                nq.append(n2)
                seen.add(n2)
            nnot = nott(node)
            if nnot not in seen:
                nq.append(nnot)
                seen.add(nnot)
        q=nq
        step+=1
        if step>50:
            break
    return -1


t = int(input())
for i in range(1, t + 1):
    r = solve()
    if r != -1:
        print(f"Case #{i}: {r}")
    else:
        print(f"Case #{i}: IMPOSSIBLE")
