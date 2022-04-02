#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k, s;
  cin >> n >> k >> s;
  vector<ll> p(n), a(n), b(n);
  for (auto& x : p) cin >> x;
  for (int i = 0; i < n; i++) {
    int x, y, z, t;
    cin >> x >> y >> z >> t;
    a[i] = max(x, y), b[i] = max({x, z, t});
  }
  ll res = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    if (__builtin_popcount(mask) == k) {
      vector<ll> v(n);
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
          v[i] = b[i];
        } else {
          v[i] = a[i];
        }
      }
      sort(v.begin(), v.end(), greater<ll>());
      ll cnt = 0, cur = s;
      for (int i = 0; i < n; i++) {
        cur += v[i];
        cnt += (cur >= p[i]);
      }
      res = max(res, cnt);
    }
  }
  cout << res << "\n";
}
