#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
  ll n;
  vector<ll> t;
  SegTree(ll _n) : n(_n), t(2 * n) {}
  void modify(ll p, ll v) {
    t[p += n] += v;
    for (p /= 2; p; p /= 2) t[p] = t[2 * p] + t[2 * p + 1];
  }
  ll query(ll l, ll r) {
    ll res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res += t[l++];
      if (r & 1) res += t[--r];
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int q;
    cin >> q;
    vector<vector<int>> g(1);
    vector<vector<array<ll, 2>>> events(1);
    vector<int> add_time(1);
    for (int i = 0, x, y; i < q; i++) {
      int t;
      cin >> t;
      if (t == 1) {
        cin >> x, x--;
        int sz = int(g.size());
        g.push_back({}), events.push_back({}), add_time.push_back(i + 1);
        g[x].push_back(sz);
      } else {
        cin >> x >> y, x--;
        events[x].push_back({y, i + 1});
      }
    }
    SegTree seg(q + 1);
    vector<ll> res(g.size());
    function<void(int, int)> dfs = [&](int node, int fa) {
      for (auto& [v, time] : events[node]) {
        seg.modify(time, v);
      }
      res[node] = seg.query(add_time[node], q + 1);
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        dfs(ne, node);
      }
      for (auto& [v, time] : events[node]) {
        seg.modify(time, -v);
      }
    };
    dfs(0, -1);
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}
