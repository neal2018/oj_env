#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    if (a[0][0] == '1') {
      cout << "-1\n";
      continue;
    }
    vector<array<int, 4>> res;
    for (int i = 0; i < n; i++) {
      for (int j = m - 1; j > 0; j--) {
        if (a[i][j] == '1') {
          res.push_back({i, j - 1, i, j});
        }
      }
    }
    for (int i = n - 1; i > 0; i--) {
      if (a[i][0] == '1') {
        res.push_back({i - 1, 0, i, 0});
      }
    }
    cout << res.size() << "\n";
    for (auto& [aa, b, c, d] : res) {
      cout << aa + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1 << "\n";
    }
  }
}
