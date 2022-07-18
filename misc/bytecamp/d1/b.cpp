#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> a{{1, 0, 0}};
  vector<set<array<int, 2>>> st(n);
  st[1].insert({0, 0});
  vector<array<int, 2>> from{{-1, -1}};
  auto check = [&](int i, int j) {
    auto [sz1, r1, s1] = a[i];
    auto [sz2, r2, s2] = a[j];
    int sz3 = sz1 + sz2, r3 = r1 + r2 + sz2;
    int s3 = sz2 * r1 + sz1 * r2 + sz1 * sz2 + s1 + s2;
    if (sz3 == n && s3 == m) {
      from.push_back({i, j});
      a.push_back({sz3, r3, s3});
      return true;
    }
    if (sz3 < n && s3 < m && st[sz3 - 1].count({r3, s3}) == 0) {
      st[sz3 - 1].insert({r3, s3});
      from.push_back({i, j});
      a.push_back({sz3, r3, s3});
    }
    return false;
  };
  if ([&] {
        for (int i = 0; i < a.size(); i++) {
          for (int j = 0; j <= min(3000, i); j++) {
            if (check(i, j)) return true;
            if (check(j, i)) return true;
          }
        }
        return false;
      }()) {
    int cur = 1;
    function<void(int)> dfs = [&](int node) {
      if (node == 0) return;
      auto [i, j] = from[node];
      int start = cur;
      dfs(i);
      cout << start << " " << ++cur << "\n";
      dfs(j);
    };
    cout << "YES\n";
    dfs(int(a.size()) - 1);
  } else {
    cout << "NO\n";
  }
}
