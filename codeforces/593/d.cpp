#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;
  vector<set<ll>> row(n), col(m);
  // vector<vector<int>> g(n, vector<int>(m));
  for (int i = 0, u, v; i < k; i++) {
    cin >> u >> v, u--, v--;
    row[u].insert(v), col[v].insert(u);
    // g[u][v] = 1;
  }
  // for (auto& r : g) {
  //   for (auto& x : r) cout << x;
  //   cout << "\n";
  // }
  ll need = n * m - k;
  ll x = 0, y = 0, walked = 1;
  ll left = 0, right = m - 1, up = 1, down = n - 1;
  auto walk_right = [&]() {
    auto it = row[x].upper_bound(y);
    ll nex_y = right;
    if (it != row[x].end()) nex_y = min(nex_y, *it - 1);
    if (nex_y <= y) return false;
    walked += nex_y - y;
    y = nex_y, right = y - 1;
    // cout << x << " " << y << "\n";
    return true;
  };
  auto walk_down = [&]() {
    auto it = col[y].upper_bound(x);
    ll nex_x = down;
    if (it != col[y].end()) nex_x = min(nex_x, *it - 1);
    if (nex_x <= x) return false;
    walked += nex_x - x;
    x = nex_x, down = x - 1;
    // cout << x << " " << y << "\n";
    return true;
  };
  auto walk_left = [&]() {
    auto it = row[x].lower_bound(y);
    ll nex_y = left;
    if (it != row[x].begin()) nex_y = max(nex_y, *--it + 1);
    if (nex_y >= y) return false;
    walked += y - nex_y;
    y = nex_y, left = nex_y + 1;
    // cout << x << " " << y << "\n";
    return true;
  };
  auto walk_up = [&]() {
    auto it = col[y].lower_bound(x);
    ll nex_x = up;
    if (it != col[y].begin()) nex_x = max(nex_x, *--it + 1);
    if (nex_x >= x) return false;
    walked += x - nex_x;
    x = nex_x, up = x + 1;
    // cout << x << " " << y << "\n";
    return true;
  };
  walk_right();
  while (true) {
    if (!walk_down()) break;
    if (!walk_left()) break;
    if (!walk_up()) break;
    if (!walk_right()) break;
  }
  // cout << walked << ' ' << need << '\n';
  if (walked == need) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
