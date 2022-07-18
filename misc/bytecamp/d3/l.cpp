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
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  Fenwick2D fen(n + 1, m + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0, v; j < m; j++) cin >> v, fen.add(i, i + 1, j, j + 1, v);
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int target;
      cin >> target;
      [&] {
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
          ll cur = fen.get(i + 1, j + 1);
          if (cur == target) {
            cout << "1\n";
            return;
          } else if (cur > target) {
            j--;
          } else {
            i++;
          }
        }
        cout << "0\n";
      }();
    } else {
      int x, y, v;
      cin >> x >> y >> v;
      fen.add(x - 1, y - 1, v);
    }
  }
}
