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
    string s;
    cin >> n >> s;
    ll res = 0;
    for (ll i = n / 2; i < n; i++) {
      if (s[i] == s[n / 2]) {
        res++;
      } else {
        break;
      }
    }
    cout << res * 2 - (n & 1) << "\n";
  }
}
