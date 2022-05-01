#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, m;
  cin >> n >> m;
  vector<ll> p(n + 1);
  iota(p.begin(), p.end(), 0);
  function<ll(ll)> find = [&](ll x) { return x == p[x] ? x : (p[x] = find(p[x])); };
  auto merge = [&](ll x, ll y) { p[find(x)] = find(y); };
  ll res = 0;
  for (int i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    if (find(x) == find(y)) {
      res++;
    } else {
      merge(x, y);
    }
  }
  cout << res << "\n";
}
