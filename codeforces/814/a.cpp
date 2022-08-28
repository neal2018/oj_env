#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    map<int, int> mp{{0, 0}};
    vector<int> dp(n + 1);
    for (int i = 0, t=0; i < n; i++) {
      t ^= a[i];
      dp[i + 1] = dp[i] + (a[i] != 0);
      if (mp.count(t)) {
        dp[i + 1] = min(dp[i + 1], dp[mp[t]] + i - mp[t]);
      }
      mp[t] = i + 1;
    }
    cout << dp.back() << "\n";
  }
}
