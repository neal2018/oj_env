#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct Fenwick2D {
  ll n, m;
  vector<vector<ll>> a;
  Fenwick2D(ll _n, ll _m) : n(_n), m(_m), a(n, vector<ll>(m)) {}
  void add(ll x, ll y, ll v) {
    for (int i = x + 1; i <= n; i += i & -i) {
      for (int j = y + 1; j <= m; j += j & -j) {
        a[i - 1][j - 1] ^= v;
      }
    }
  }
  void add(ll x1, ll x2, ll y1, ll y2, ll v) {
    // [(x1, y1), (x2, y2))
    add(x1, y1, v);
    add(x1, y2, v), add(x2, y1, v);
    add(x2, y2, v);
  }
  ll sum(ll x, ll y) {  // [(0, 0), (x, y))
    ll ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
      for (int j = y; j > 0; j -= j & -j) {
        ans ^= a[i - 1][j - 1];
      }
    }
    return ans;
  }
};

constexpr ll MAX = 5000;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  ll q;
  cin >> q;
  Fenwick2D seg(MAX, MAX);
  vector<ll> hash(q);
  for (auto &x : hash) x = rng();
  vector<array<ll, 4>> qs(q);
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      auto &[x1, y1, x2, y2] = qs[i];
      cin >> x1 >> y1 >> x2 >> y2;
      x1--, y1--;
      seg.add(x1, x2, y1, y2, hash[i]);
    } else if (t == 2) {
      int j;
      cin >> j, j--;
      auto &[x1, y1, x2, y2] = qs[j];
      seg.add(x1, x2, y1, y2, hash[j]);
    } else {
      ll x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      auto t1 = seg.sum(x1, y1);
      auto t2 = seg.sum(x2, y2);
      // cout << t1 << " " << t2 << "\n";
      if (t1 == t2) {
        cout << "Y";
      } else {
        cout << "N";
      }
    }
  }
  cout << "\n";
}
