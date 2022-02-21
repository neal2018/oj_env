#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

constexpr ld eps = 1e-10;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll mini = *min_element(a.begin(), a.end());
  ll maxi = *max_element(a.begin(), a.end());
  {
    ld left = mini, right = maxi;
    auto check = [&](ld mid) {
      vector<ld> b(n);
      for (int i = 0; i < n; i++) b[i] = a[i] - mid;
      vector<ld> dp1(n), dp2(n);
      dp1[0] = b[0];
      for (int i = 1; i < n; i++) {
        dp1[i] = max(dp1[i - 1], dp2[i - 1]) + b[i];
        dp2[i] = dp1[i - 1];
      }
      return max(dp1[n - 1], dp2[n - 1]) > 0;
    };
    while (right - left > eps) {
      ld mid = (left + right) / 2;
      if (check(mid)) {
        left = mid;
      } else {
        right = mid;
      }
    }
    cout << left << "\n";
  }
  {
    ll left = mini, right = maxi;
    auto check = [&](ll mid) {
      auto b = a;
      for (auto& x : b) x = x >= mid ? 1 : -1;
      vector<ll> dp1(n), dp2(n);
      dp1[0] = b[0];
      for (int i = 1; i < n; i++) {
        dp1[i] = max(dp1[i - 1], dp2[i - 1]) + b[i];
        dp2[i] = dp1[i - 1];
      }
      return max(dp1[n - 1], dp2[n - 1]) > 0;
    };
    while (right > left) {
      ll mid = (left + right + 1) / 2;
      if (check(mid)) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }
    cout << left << "\n";
  }
}
