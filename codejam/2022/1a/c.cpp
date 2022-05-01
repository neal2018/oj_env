#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_num = 1; case_num <= T; case_num++) {
    cout << "Case #" << case_num << ": ";
    ll n, w;
    cin >> n >> w;
    vector<vector<ll>> a(n);
    for (auto& v : a) {
      for (auto& x : v) cin >> x;
    }
    vector dp(n, vector<ll>(n, inf));
    for (int len = 1; len <= n; len++) {
      for (int l = 0; l + len <= n; l++) {
        int r = l + len - 1;
        if (len == 1) {
          dp[l][r] = accumulate(a[l].begin(), a[l].end(), 0ll);
        } else {
          
        }
      }
    }
  }
}
