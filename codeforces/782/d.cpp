#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> c(n);
    for (auto& x : c) cin >> x;
    ll one = accumulate(c.begin(), c.end(), 0ll) / n;
    vector<ll> res(n), mark(n);
    ll cur = 0;
    for (ll i = n - 1; i >= 1; i--) {
      mark[i] += 1;
      if (i - one >= 0) mark[i - one] -= 1;
      cur += mark[i];
      if (c[i] - cur > 0) res[i] = 1, one--;
    }
    res[0] = one;
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}
