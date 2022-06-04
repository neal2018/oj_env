#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll res = 0;
    if (k > n) res += n * (k - n), k = n;
    ll maxi = 0, cur = 0;
    for (auto i : views::iota(0, n)) {
      cur += a[i];
      if (i - k >= 0) cur -= a[i - k];
      if (i >= k - 1) maxi = max(maxi, cur);
    }
    cout << res + maxi + k * (k - 1) / 2 << "\n";
  }
}
