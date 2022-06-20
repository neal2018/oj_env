#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector a(n, vector<int>(m));
  for (auto& r : a) {
    for (auto& x : r) cin >> x, x--;
  }
  vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  auto check = [&]() {
    vector<pair<int, int>> pos(n * m);
    for (auto i : views::iota(0, n)) {
      for (auto j : views::iota(0, m)) {
        pos[a[i][j]] = {i, j};
      }
    }
    vector<ll> p(n * m);  // number
    iota(p.begin(), p.end(), 0);
    function<ll(ll)> find = [&](ll x) { return x == p[x] ? x : (p[x] = find(p[x])); };
    auto merge = [&](ll x, ll y) { p[find(x)] = find(y); };
    for (auto i : views::iota(1, n * m)) {
      auto [x, y] = pos[i];
      if ([&] {
            for (auto& [dx, dy] : directions) {
              int xx = x + dx, yy = y + dy;
              if (0 <= xx && xx < n && 0 <= yy && yy < m) {
                if (find(a[xx][yy]) == find(i - 1)) {
                  merge(i, i - 1);
                  return true;
                }
              }
            }
            return false;
          }()) {
        continue;
      } else {
        return false;
      }
    }
  };
  // if (check()) {
  //   cout << "0\n";
  //   return 0;
  // }
  ll res = 0, good = 1, can_1 = 0;
  vector<ll> p(n * m, -1);  // number
  function<ll(ll)> find = [&](ll x) { return p[x] < 0 ? x : (p[x] = find(p[x])); };
  auto merge = [&](ll x, ll y) {
    ll rx = find(x), ry = find(y);
    if (rx == ry) return false;
    p[ry] += p[rx];
    p[rx] = ry;
    return true;
  };
  vector<pair<int, int>> pos(n * m);
  for (auto i : views::iota(0, n)) {
    for (auto j : views::iota(0, m)) {
      pos[a[i][j]] = {i, j};
    }
  }
  for (auto i : views::iota(1, n * m)) {
    auto [x, y] = pos[i];
    if ([&] {
          for (auto& [dx, dy] : directions) {
            int xx = x + dx, yy = y + dy;
            if (0 <= xx && xx < n && 0 <= yy && yy < m) {
              if (find(a[xx][yy]) == find(i - 1)) {
                merge(i, i - 1);
                return true;
              }
            }
          }
          return false;
        }()) {
      continue;
    } else {
      good = 0;
      ll sz = -p[find(i - 1)];
      for (auto& [dx, dy] : directions) {
        int xx = x + dx, yy = y + dy;
        if (0 <= xx && xx < n && 0 <= yy && yy < m) {
          if (find(a[xx][yy]) == find(i - 1)) {
            merge(i, i - 1);
            return true;
          }
        }
      }
    }
  }
  if (good) {
    cout << "0\n";
    return 0;
  }
}
