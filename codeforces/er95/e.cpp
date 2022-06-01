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
    vector<string> a(2);
    cin >> n >> a[0] >> a[1];
    auto get_pos = [&](const string& s) -> pair<ll, ll> {
      ll p1 = -1, p2 = -1;
      for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
          if (p1 == -1) p1 = i;
          p2 = i;
        }
      }
      return {p1, p2};
    };
    auto [l1, r1] = get_pos(a[0]);
    auto [l2, r2] = get_pos(a[1]);
    if (l1 == -1) {
      cout << r2 - l2 << "\n";
      continue;
    }
    if (l2 == -1) {
      cout << r1 - l1 << "\n";
      continue;
    }
    ll cur0 = 0, cur1 = 0;
    for (ll i = min(l1, l2); i <= max(r1, r2); i++) {
      ll n_cur0 = cur0 + 1, n_cur1 = cur1 + 1;
      if (a[0][i] == '*') n_cur1 = min(cur0, cur1) + 2;
      if (a[1][i] == '*') n_cur0 = min(cur0, cur1) + 2;
      cur0 = n_cur0, cur1 = n_cur1;
    }
    cout << min(cur0, cur1) - 1 << "\n";
  }
}
