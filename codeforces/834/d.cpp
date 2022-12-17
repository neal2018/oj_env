#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll a, ll b, ll res = 1) {
  for (; b; b /= 2, (a *= a))
    if (b & 1) (res *= a);
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n >> m;
    ll res = n * m;
    ll cnt_2 = 0, cnt_5 = 0;
    ll nn = n;
    while (n % 2 == 0) cnt_2++, n /= 2;
    while (n % 5 == 0) cnt_5++, n /= 5;
    for (int i = 1; i < 19; i++) {
      ll need_5 = max(0ll, i - cnt_5);
      ll need_2 = max(0ll, i - cnt_2);
      ll total = power(2, need_2) * power(5, need_5);
      if (total > m) break;
      ll cur = m / total * total;
      res = nn * cur;
    }
    cout << res << "\n";
  }
}
