#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, a, b, p, q, r, s;
  cin >> n >> a >> b >> p >> q >> r >> s;
  vector<string> g(q - p + 1, string(s - r + 1, '.'));
  for (ll i = p; i <= q; i++) {
    for (ll j = r; j <= s; j++) {
      if (i - a == j - b) {
        ll k = i - a;
        if (max(1 - a, 1 - b) <= k && k <= min(n - a, n - b)) {
          g[i - p][j - r] = '#';
        }
      }
      if (i - a == -(j - b)) {
        ll k = i - a;
        if (max(1 - a, b - n) <= k && k <= min(n - a, b - 1)) {
          g[i - p][j - r] = '#';
        }
      }
    }
  }
  for (auto& t : g) cout << t << "\n";
}