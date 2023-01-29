#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k, x;
    cin >> n >> k >> x;
    vector<vector<int>> res{{}};
    vector<int> seen(n + 1);
    for (int i = 1; i <= n; i++) {
      if (seen[i]) continue;
      if (i == x) {
        res.push_back({x});
      } else {
        int cur = x ^ i;
        if (cur <= n && seen[cur] == 0) {
          seen[cur] = 1;
          res.push_back({cur, i});
          seen[cur] = 1;
        } else {
          res[0].push_back(i);
        }
      }
      seen[i] = 1;
    }
    if (k > res.size()) {
      cout << "NO\n";
      continue;
    }
    while (res.size() > k) {
      auto t = res.back();
      res.pop_back();
      for (auto& xx : t) res[0].push_back(xx);
    }
    if (![&] {
          int total = 0;
          for (auto& xx : res[0]) total ^= xx;
          return total == x;
        }()) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (auto& v : res) {
      cout << v.size() << " ";
      for (auto& xx : v) cout << xx << " ";
      cout << "\n";
    }
  }
}