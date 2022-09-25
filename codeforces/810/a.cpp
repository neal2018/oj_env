#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(k);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end(), greater<>());
    auto f = [&](ll _n, ll _m, vector<ll> aa) {
      ll total = _m, i = 0;
      while (total >= 2 && i < k) {
        ll rows = aa[i] / _n;
        if (rows >= 2) {
          total -= 2;
        } else {
          break;
        }
        aa[i] -= 2 * _n, i++;
      }
      for (int ii = 0; ii < i && total > 0; ii++) {
        ll rows = aa[ii] / _n;
        total -= rows;
      }
      return total <= 0;
    };
    if (f(n, m, a) || f(m, n, a)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
