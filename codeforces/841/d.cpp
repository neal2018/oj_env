#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    for (auto& r : a) {
      for (auto& x : r) cin >> x;
    }
    auto check = [&](ll mid) {
      vector pre(n + 1, vector<int>(m + 1));
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          pre[i][j] = (a[i - 1][j - 1] >= mid) + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
      }
      for (int i = 0; i <= n - mid; i++) {
        for (int j = 0; j <= m - mid; j++) {
          auto sum = pre[i + mid][j + mid] + pre[i][j] - pre[i + mid][j] - pre[i][j + mid];
          if (sum >= mid * mid) return true;
        }
      }
      return false;
    };
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << l << "\n";
  }
}
