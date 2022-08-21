#include <iostream>
#include <cstring>
#include <unordered_map>

#define int long long

using namespace std;

const int N = 100010;
const int mod = 1e9 + 7;

int n;

struct SAM {
    struct Node {
        int fa, len;
        unordered_map<int, int> ch;
    }node[N << 1];
    int q[N];
    int last = 1, tot = 1;
    int pos[N];
    int ch[N], fa[N];
    int d[N];
    int e[N << 1], ne[N << 1], h[N], idx;

    SAM() {
        memset(h, -1, sizeof h);
        pos[0] = 1;
    }

    void insert(int u, int v) {
        e[idx] = v, ne[idx] = h[u], h[u] = idx++;
    }

    int extend(int c, int last) {
        int p = last, np = ++tot;
        node[np].len = node[p].len + 1;
        for (; p && !node[p].ch[c]; p = node[p].fa) node[p].ch[c] = np;
        if (!p) node[np].fa = 1;
        else {
            int q = node[p].ch[c];
            if (node[q].len == node[p].len + 1) node[np].fa = q;
            else {
                int nq = ++tot;
                node[nq] = node[q], node[nq].len = node[p].len + 1;
                node[q].fa = node[np].fa = nq;
                for (; p && node[p].ch[c] == q; p = node[p].fa) node[p].ch[c] = nq;
            } 
        }
        return np;
    }

    void dfs(int u, int father) {
        pos[u] = extend(d[u], pos[father]);
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == father) continue;
            dfs(j, u);
        }
    }

    int solve() {
        int res = 0;
        for (int i = 2; i <= tot; i++)
            res += node[i].len - node[node[i].fa].len;
        return res;
    }
}sam;

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        sam.insert(u, v);
        sam.insert(v, u);
        sam.d[u]++, sam.d[v]++;
    }
    sam.dfs(1, 0);
    cout << sam.solve() << '\n';
    return 0;
}
