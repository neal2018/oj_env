#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

struct Basis {
  const int SZ = 32;
  vector<ll> a = vector<ll>(SZ);
  Basis(int sz) : SZ(sz), a(sz) {}
  bool insert(ll x) {
    for (int i = SZ - 1; i >= 0; i--) {
      if (x >> i) {
        if (!a[i]) {
          a[i] = x;
          return true;
        } else {
          x ^= a[i];
        }
      }
    }
    return false;
  }
};

struct SegTree {
  int n;
  vector<ll> t;
  SegTree(int _n) : n(_n) { t.resize(2 * n); }
  void apply(ll x, ll v) { t[x] = (t[x] + v); }
  void modify(ll l, ll r, ll v) {
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
    }
  }
  ll query(ll p) {
    ll res = t[p += n];
    for (p /= 2; p > 0; p /= 2) res = (res + t[p]);
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  SegTree seg(n);
  for (int i = 0; i < n; i++) {
    cin >> seg.t[i + n];
  }
  while (q--) {
    int t = 0;
    cin >> t;
    if (t == 1) {
      ll l, r, x;
      cin >> l >> r >> x, l--;
      seg.modify(l, r, x);
    } else {
      ll l, r;
      cin >> l >> r, l--;
      if (r - l > 32) {
        cout << "Yes\n";
      } else {
        Basis bs(32);
        [&] {
          for (ll i = l; i < r; i++) {
            if (!bs.insert(seg.query(i))) {
              cout << "Yes\n";
              return;
            }
          }
          cout << "No\n";
        }();
      }
    }
  }
}
