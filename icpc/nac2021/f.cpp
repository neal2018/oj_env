#include <bits/stdc++.h>
using namespace std;

#define FOR(x, n) for (int x = 0; x < n; x++)
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const char nl = '\n';

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<ll> f(n, 1), g(n, 1);
  for (ll i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) {
      f[i] = f[i - 1] + 1;
    }
  }
  for (ll i = n - 2; i >= 0; i--) {
    if (a[i] > a[i + 1]) {
      g[i] = g[i + 1] + 1;
    }
  }
  vector<ll> t = {-1, 0};
  t.reserve(3 * n);
  for (auto& x : a) t.push_back(x), t.push_back(0);
  t.push_back(-2);
  ll m = t.size();
  ll r = 0, c = 0;
  vector<ll> p(m, 0);
  for (int i = 1; i < m - 1; i++) {
    if (i < r + c) p[i] = min(p[2 * c - i], r + c - i);
    while (t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
    if (i + p[i] > r + c) r = p[i], c = i;
  }
  ll res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, min(f[i] + g[i] - 1, p[i * 2 + 2]));
  }
  cout << (res <= 1 ? -1 : res) << "\n";
}