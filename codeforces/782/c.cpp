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
    ll n, a, b;
    cin >> n >> b >> a;
    vector<ll> pos(n), pre(n + 1);
    for (auto& x : pos) cin >> x;
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + pos[i];
    ll res = a * pre[n];
    for (int i = 0; i < n; i++) {
      // (a+b)*a[i] + a*(sum[i+1...n]) - a*a[i]
      ll cur = (a + b) * pos[i] + a * (pre[n] - pre[i + 1]) - a * pos[i] * (n - 1 - i);
      res = min(res, cur);
    }
    cout << res << "\n";
  }
}
