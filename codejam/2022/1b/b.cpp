#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_num = 1; case_num <= T; case_num++) {
    cout << "Case #" << case_num << ": ";
    ll n, m;
    cin >> n >> m;
    vector a(n, vector<ll>(m));
    for (auto& r : a) {
      for (auto& x : r) cin >> x;
      sort(r.begin(), r.end());
    }
    ll dp0 = 0, dp1 = 0, pre_mini = 0, pre_maxi = 0;
    for (auto& r : a) {
      ll len = r.back() - r[0];
      ll n_dp0 = len + min(dp0 + abs(pre_mini - r.back()), dp1 + abs(pre_maxi - r.back()));
      ll n_dp1 = len + min(dp0 + abs(pre_mini - r[0]), dp1 + abs(pre_maxi - r[0]));
      pre_mini = r[0], pre_maxi = r.back();
      dp0 = n_dp0, dp1 = n_dp1;
      // cout << dp0 << ' ' << dp1 << "\n";
    }
    cout << min(dp0, dp1) << "\n";
  }
}
