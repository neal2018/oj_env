// from https://codeforces.com/gym/103486/submission/148676917

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  vector<ll> sub(n), up(n), mx1(n), mx2(n), mx3(n), sup(n);
  vector<int> f(n), id1(n, -1), id2(n, -1), id3(n, -1);
  function<void(int, int)> dfs2 = [&](int u, int fa) {
    f[u] = fa;
    for (auto [v, w] : g[u]) {
      if (v == fa) continue;
      dfs2(v, u);
      int p = v;
      ll mx = mx1[p] + w;
      if (mx > mx1[u]) {
        swap(mx, mx1[u]);
        swap(p, id1[u]);
      }
      if (mx > mx2[u]) {
        swap(mx, mx2[u]);
        swap(p, id2[u]);
      }
      if (mx > mx3[u]) {
        swap(mx, mx3[u]);
        swap(p, id3[u]);
      }
      sub[u] = max(sub[u], mx1[u] + mx2[u]);
      sub[u] = max(sub[u], sub[v]);
    }
  };
  dfs2(0, -1);

  function<void(int, int, ll, ll)> dfs3 = [&](int u, int fa, ll c, ll s) {
    ll sm1 = 0, sm2 = 0;
    int si1 = -1, si2 = -1;
    for (auto [v, w] : g[u]) {
      if (v == fa) continue;
      int p = v;
      ll ss = sub[p];
      if (ss > sm1) {
        swap(ss, sm1);
        swap(si1, p);
      }
      if (ss > sm2) {
        swap(ss, sm2);
        swap(si2, p);
      }
    }
    for (auto [v, w] : g[u]) {
      if (v == fa) continue;
      // u -> up[v]
      ll mx = c;
      if (id1[u] != v) mx = max(mx, mx1[u]);
      if (id2[u] != v) mx = max(mx, mx2[u]);
      up[v] = mx;
      vector<ll> es{c};
      if (id1[u] != v) es.push_back(mx1[u]);
      if (id2[u] != v) es.push_back(mx2[u]);
      if (id3[u] != v) es.push_back(mx3[u]);
      sort(es.begin(), es.end(), greater<ll>());
      ll s2 = es[1] + es[0];
      if (si1 != v) s2 = max(s2, sm1);
      if (si2 != v) s2 = max(s2, sm2);
      sup[v] = max(s, s2);
      dfs3(v, u, mx + w, max({s, s2, mx + w}));
    }
  };
  dfs3(0, -1, 0, 0);
  int q;
  cin >> q;
  while (q--) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    assert(u == f[v] || v == f[u]);
    if (u == f[v]) swap(u, v);
    cout << max({sub[u], mx1[u] + up[u] + w, sup[u]}) << '\n';
  }
}
