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
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n), twos(n), pre_twos(n + 1), zeros{-1};
    for (int i = 0; i < n; i++) {
      auto& x = a[i];
      cin >> x;
      if (x == 0) zeros.push_back(i);
      if (abs(x) == 2) twos[i] = 1;
    }
    for (int i = 0; i < n; i++) pre_twos[i + 1] = pre_twos[i] + twos[i];
    zeros.push_back(n);
    ll sz = zeros.size(), res = 0, pre = n, last = 0;
    auto update = [&](ll l, ll r) {
      ll t = pre_twos[r] - pre_twos[l];
      if (t > res) res = t, pre = l, last = n - r;
    };
    for (int ii = 0; ii < sz - 1; ii++) {
      // zeros[ii] + 1,  zeros[ii + 1] - 1
      ll neg = 0, first_neg = -1, last_neg = -1;
      for (ll i = zeros[ii] + 1; i < zeros[ii + 1]; i++) {
        if (a[i] < 0) {
          neg++;
          if (first_neg == -1) first_neg = i;
          last_neg = i;
        }
      }
      if (neg % 2 == 0) {
        update(zeros[ii] + 1, zeros[ii + 1]);
      } else {
        update(first_neg + 1, zeros[ii + 1]);
        update(zeros[ii] + 1, last_neg);
      }
    }
    cout << pre << " " << last << "\n";
  }
}
