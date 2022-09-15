#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick2D {
  ll n, m;
  vector<vector<ll>> a;
  Fenwick2D(ll _n, ll _m) : n(_n), m(_m), a(n, vector<ll>(m)) {}
  void add(ll x, ll y, ll v) {
    // range add [(x1, y1), (n, m))
    for (ll i = x + 1; i <= n; i += i & -i) {
      for (ll j = y + 1; j <= m; j += j & -j) {
        a[i - 1][j - 1] += v;
      }
    }
  }
  void add(ll x1, ll y1, ll x2, ll y2, ll v) {
    // range add [(x1, y1), (x2, y2))
    add(x1, y1, v), add(x2, y2, v);
    add(x1, y2, -v), add(x2, y1, -v);
  }
  ll get(ll x, ll y) {
    // point get (x+1, y+1)
    ll ans = 0;
    for (ll i = x; i > 0; i -= i & -i) {
      for (ll j = y; j > 0; j -= j & -j) {
        ans += a[i - 1][j - 1];
      }
    }
    return ans;
  }
  ll get(ll x1, ll y1, ll x2, ll y2) {
    return get(x2, y2) + get(x1, y1) - get(x1, y2) - get(x2, y1);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    Fenwick2D tree(1001, 1001);
    for (ll i = 0, h, w; i < n; i++) {
      cin >> h >> w;
      tree.add(h, w, h * w);
    }
    while (q--) {
      ll hs, ws, hb, wb;
      cin >> hs >> ws >> hb >> wb;
      ll res = tree.get(hs + 1, ws + 1, hb, wb);
      cout << res << "\n";
    }
  }
}
