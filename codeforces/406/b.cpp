#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
  ll n;
  vector<vector<pair<ll, ll>>> g;
  SegTree(ll _n) : n(_n), g(3 * n) {}
  void add_edge(ll u, ll v, ll w, ll d = 1) {
    if (d != 1) {
      swap(u, v);
      if (u < n) u += 2 * n;
    }
    g[u].push_back({v, w});
  }
  void query(ll l, ll r, ll from, ll w, ll d = 1) {
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) add_edge(from + n, l++, w, d);
      if (r & 1) add_edge(from + n, --r, w, d);
    }
  }
};

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q, s;
  cin >> n >> q >> s, s--;
  SegTree seg(n);
  for (int i = n - 1; i > 0; i--) {
    seg.add_edge(i, 2 * i, 0), seg.add_edge(i, 2 * i + 1, 0);
  }
  for (int i = n - 1; i >= 0; i--) {
    seg.add_edge(i + n, (i + n) / 2 + 2 * n, 0);
  }
  for (int i = n - 1; i > 0; i--) {
    seg.add_edge(i + 2 * n, i / 2 + 2 * n, 0);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      ll u, v, w;
      cin >> u >> v >> w, u--, v--;
      seg.add_edge(u + n, v + n, w);
    } else {
      ll u, l, r, w;
      cin >> u >> l >> r >> w, u--, l--;
      seg.query(l, r, u, w, t == 2 ? 1 : -1);
    }
  }
  int root = n + s;
  set<pair<ll, ll>> st{{0, root}};
  vector<ll> dist(3 * n, inf);
  dist[root] = 0;
  while (st.size()) {
    auto [cost, node] = *st.begin();
    st.erase(st.begin());
    for (auto& [ne, w] : seg.g[node]) {
      if (cost + w < dist[ne]) {
        dist[ne] = cost + w, st.insert({dist[ne], ne});
      }
    }
  }
  for (int i = n; i < 2 * n; i++) {
    cout << (dist[i] == inf ? -1 : dist[i]) << " ";
  }
}
