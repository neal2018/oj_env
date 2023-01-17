#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector a(n, vector(m, 0));
  for (auto& r : a) {
    for (auto& x : r) cin >> x;
  }
  array<array<int, 2>, 2> dp = {{{0, 1}, {0, 1}}};
  for (int i = 0; i < n; i++) {
    array<array<int, 2>, 2> ndp = {{{inf, inf}, {inf, inf}}};
    for (auto flip : {0, 1}) {
      for (auto pre : {0, 1}) {
        for (auto pre2 : {0, 1}) {
          if ([&] {
                for (int j = 0; j < m; j++) {
                  int cur = a[i][j] ^ pre;
                  if (i > 0 && (cur == (a[i - 1][j] ^ pre2))) continue;
                  if (i < n - 1 && (cur == (a[i + 1][j] ^ flip))) continue;
                  if (j > 0 && (cur == (a[i][j - 1] ^ pre))) continue;
                  if (j < m - 1 && (cur == (a[i][j + 1] ^ pre))) continue;
                  return false;
                }
                return true;
              }()) {
            ndp[pre][flip] = min(ndp[pre][flip], dp[pre2][pre] + flip);
          }
        }
      }
    }
    swap(dp, ndp);
  }

  int res = inf;
  for (auto& r : dp) {
    for (auto& x : r) {
      res = min(res, x);
    }
  }
  cout << (res == inf ? -1 : res);
}
