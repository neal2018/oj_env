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
    vector<ll> a(n);
    ll non_zero = 0, has_zero = 0;
    for (auto& x : a) cin >> x, non_zero += (x != 0), has_zero |= (x == 0);
    ll has_same = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == a[i + 1]) has_same = 1;
    }
    ll res = non_zero;
    if (!has_same && !has_zero) {
      res++;
    }
    cout << res << "\n";
  }
}
