#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

struct SegTree {
  ll n;
  vector<int> t;
  SegTree(ll _n) : n(_n), t(2 * n) {}
  void modify(ll p, int v) {
    t[p += n] += v;
    for (p /= 2; p; p /= 2) t[p] = max(t[2 * p], t[2 * p + 1]);
  }
  int query(ll l, ll r) {
    int res = -1e9;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res = max(res, t[l++]);
      if (r & 1) res = max(res, t[--r]);
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back({v, 1}), g[v].push_back({u, 1});
    }
    vector<int> parent(n), deep(n), hson(n), top(n), sz(n);
    vector<int> sub_deep(n);
    function<int(int, int, int)> dfs = [&](int node, int fa, int dep) {
      deep[node] = dep, sz[node] = 1, parent[node] = fa;
      for (auto& [ne, w] : g[node]) {
        if (ne == fa) continue;
        sz[node] += dfs(ne, node, dep + 1);
        if (!hson[node] || sz[ne] > sz[hson[node]]) hson[node] = ne;
        sub_deep[node] = max(sub_deep[node], sub_deep[ne] + 1);  // not include self
      }
      return sz[node];
    };
    dfs(0, -1, 0);
    int to = int(max_element(deep.begin(), deep.end()) - deep.begin());
    vector<int> chain;
    for (int cur = to; cur != -1; cur = parent[cur]) chain.push_back(cur);
    reverse(chain.begin(), chain.end());
    int m = (int)chain.size();
    set<int> chain_st;
    for (auto& node : chain) chain_st.insert(node);
    vector<int> remain(n);
    function<int(int)> get_remain = [&](int node) {
      for (auto& [ne, w] : g[node]) {
        if (ne == parent[node]) continue;
        get_remain(ne);
        if (!chain_st.count(ne)) remain[node] = max(remain[node], remain[ne] + 1);
      }
      return remain[node];
    };
    get_remain(0);
    SegTree seg1(m), seg2(m);
    for (int i = 0; i < m; i++) seg1.modify(i, deep[chain[i]] + remain[chain[i]]);
    for (int i = 0; i < m; i++) seg2.modify(i, m - 1 - deep[chain[i]] + remain[chain[i]]);
    for (int x = 1; x <= n; x++) {
      int mini = 1e9, pos = 0;
      for (int i = 0; i < m; i++) {
        int cur = chain[i];
        while (pos < m && deep[chain[pos]] < i - deep[chain[pos]] + x) pos++;
        pos--;
        int maxi = max(sub_deep[cur] + min(x, deep[cur]), seg1.query(0, pos + 1));
        maxi = max(maxi, seg2.query(pos + 1, i + 1) - (m - 1 - i) + x);
        if (maxi <= mini) {
          mini = maxi;
        }
      }
      cout << mini << " ";
    }
    cout << "\n";
  }
}
