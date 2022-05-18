#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, k, cnt = 0;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto& x : a) cin >> x, cnt += (x == 0);
  ll sum = accumulate(a.begin(), a.end(), 0ll);
  if (sum + cnt * k < 0 || sum - cnt * k > 0) {
    cout << "-1\n";
    return 0;
  }
  ll res = 0;
  for (int i = 0; i < n; i++) {
    ll zero = 0, val = 0;
    for (int j = i; j < n; j++) {
      zero += (a[j] == 0), val += a[j];
      ll down = max(-zero * k, -(sum + (cnt - zero) * k));
      ll up = min(zero * k, -(sum - (cnt - zero) * k));
      res = max({res, abs(val + up), abs(val + down)});
    }
  }
  cout << res + 1 << "\n";
}
