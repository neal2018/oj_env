#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> edges(n);
  for (int i = 0, u, v, c; i < n - 1; i++) {
    cin >> u >> v >> c, u--, v--, c--;
    edges[c].push_back({u, v});
  }
  vector<int> p(n, -1);
  vector<pair<int, int>> history;
  history.reserve(2 * n);
  function<int(int)> find = [&](int x) { return p[x] < 0 ? x : find(p[x]); };
  auto merge = [&](int x, int y) {
    int r_x = find(x), r_y = find(y);
    if (r_x == r_y) return;
    int sz_x = -p[r_x], sz_y = -p[r_y];
    if (sz_x < sz_y) swap(r_x, r_y), swap(x, y), swap(sz_x, sz_y);
    history.push_back({r_x, p[r_x]});
    p[r_x] = -(sz_x + sz_y);
    history.push_back({r_y, p[r_y]});
    p[r_y] = r_x;
  };
  auto rollback = [&](ll pos) {
    while (history.size() > pos) {
      auto [x, px] = history.back();
      history.pop_back();
      p[x] = px;
    }
  };
  ll res = 0;
  function<void(int, int)> dfs = [&](int l, int r) {
    if (l + 1 == r) {
      for (auto& [x, y] : edges[l]) res += (ll)p[find(x)] * p[find(y)];
      return;
    }
    int mid = (l + r) / 2;
    {
      ll save = history.size();
      for (int i = mid; i < r; i++) {
        for (auto& [x, y] : edges[i]) merge(x, y);
      }
      dfs(l, mid);
      rollback(save);
    }
    {
      ll save = history.size();
      for (int i = l; i < mid; i++) {
        for (auto& [x, y] : edges[i]) merge(x, y);
      }
      dfs(mid, r);
      rollback(save);
    }
  };
  dfs(0, n);
  cout << res << "\n";
}
