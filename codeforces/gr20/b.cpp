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
    string s;
    cin >> s;
    ll n = s.size();
    ll cur = 0, f = 1;
    for (int i = 0; i < n; i++) {
      cur += (s[i] == 'A' ? 1 : -1);
      if (cur < 0) f = 0;
    }
    cout << (s[n - 1] == 'B' && f ? "YES\n" : "NO\n");
  }
}
