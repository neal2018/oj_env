#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll cur = 0, need = 0, g = 0;
  vector<ll> res(n);
  for (int i = 0; i < n; i++) {
    cur++;
    ll gg = gcd(g, a[i]);
    if (a[i] == 1 || (cur >= gg && gg != 1)) {
      need++, g = 0, cur = 0;
    } else {
      g = gg;
      if (g == 1) {
        ll t = 0, cc = cur;
        cur = 0;
        for (int j = i; j >= i - cc; j--) {
          t = gcd(t, a[j]);
          if (t != 1) {
            g = t;
            cur++;
          } else {
            break;
          }
        }
        // g = a[i], cur = 1;
      }
    }
    res[i] = need;
  }
  for (auto& x : res) cout << x << " ";
  cout << "\n";
}
