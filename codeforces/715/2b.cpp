#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  string s;
  auto f = [&]() {
    cin >> n >> s;
    ll t = count(s.begin(), s.end(), 'T');
    ll m = count(s.begin(), s.end(), 'M');
    if (2 * m != t) return false;
    for (ll i = 0, tt = 0, mm = 0; i < n; i++) {
      s[i] == 'T' ? tt++ : mm++;
      if (tt < mm) return false;
    }
    for (ll i = n - 1, tt = 0, mm = 0; i >= 0; i--) {
      s[i] == 'T' ? tt++ : mm++;
      if (tt < mm) return false;
    }
    return true;
  };
  for (; T--;) cout << (f() ? "YES\n" : "NO\n");
}