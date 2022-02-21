#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  ll mini = 1e18, maxi = -1e18;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first, a[i].second = i;
    mini = min(mini, a[i].first), maxi = max(maxi, a[i].first);
  }
  sort(a.begin(), a.end());
  vector<ll> b(n - 1), dp1(n - 1), dp2(n - 1), from(n - 1), select(n - 1), res(n);
  for (int i = 0; i < n - 1; i++) b[i] = a[i + 1].first - a[i].first;
  for (int i = 2; i < n - 1; i++) {
    dp2[i] = dp2[i - 1];
    if (dp1[i - 1] > dp2[i]) {
      from[i] = 1, dp2[i] = dp1[i - 1];
    }
    if (i < n - 3) dp1[i] = b[i] + dp2[i - 2];
  }
  for (int i = n - 2; i >= 0;) {
    if (from[i] == 1) {
      select[i - 1] = 1, i = i - 3;
    } else {
      i--;
    }
  }
  cout << (maxi - mini - dp2.back()) << " " << accumulate(select.begin(), select.end(), 0ll) + 1
       << "\n";
  for (int i = 0, cur = 1; i < n; i++) {
    auto& [v, pos] = a[i];
    res[pos] = cur;
    if (i < n - 1 && select[i]) cur++;
  }
  for (int i = 0; i < n; i++) cout << res[i] << " ";
  cout << "\n";
}
