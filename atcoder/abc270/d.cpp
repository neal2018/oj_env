#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  vector<int> dp(n + 1), dp2(n + 1);
  for (int i = 0; i <= n; i++) {
    int id = -1;
    for (int j = 0; j < k; j++) {
      if (a[j] > i) break;
      if (a[j] + dp2[i - a[j]] > dp[i]) {
        dp[i] = a[j] + dp2[i - a[j]];
        id = j;
      }
    }
    if (id != -1) {
      dp2[i] = dp[i - a[id]];
    }
  }
  cout << dp[n] << "\n";
}
