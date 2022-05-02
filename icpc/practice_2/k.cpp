#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr ll MOD = 1000000782;

struct SegTree {
  int n;
  vector<ll> t;
  SegTree(int _n) : n(_n) { t.resize(2 * n); }
  void apply(ll x, ll v) { t[x] = (t[x] + v) % MOD; }
  void modify(ll l, ll r, ll v) {
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
    }
  }
  ll query(ll p) {
    ll res = t[p += n];
    for (p /= 2; p > 0; p /= 2) res = (res + t[p]) % MOD;
    return res;
  }
};

struct SegTree2D {
  int n;
  vector<SegTree> t;
  SegTree2D(int _n) : n(_n) { t.resize(2 * n, SegTree(n)); }
  void apply(ll x, ll yl, ll yr, ll v) { t[x].modify(yl, yr, v); }
  void modify(ll l, ll r, ll yl, ll yr, ll v) {
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) apply(l++, yl, yr, v);
      if (r & 1) apply(--r, yl, yr, v);
    }
  }
  ll query(ll p, ll yp) {
    ll res = t[p += n].query(yp);
    for (p /= 2; p > 0; p /= 2) res = (res + t[p].query(yp)) % MOD;
    return res;
  }
};

constexpr ll MAX = 2503;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  ll q;
  cin >> q;
  SegTree2D seg(MAX);
  vector<ll> hash(q + 1, 1);
  ll BASE = 102240;
  for (int i = 0; i < q; i++) hash[i + 1] = (hash[i] * BASE) % MOD;
  vector<array<ll, 4>> qs(q);
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      auto &[x1, y1, x2, y2] = qs[i];
      cin >> x1 >> y1 >> x2 >> y2;
      x1 = (x1 + 1) / 2, y1 = (y1 + 1) / 2, x2 = (x2 + 1) / 2, y2 = (y2 + 1) / 2;
      seg.modify(x1, x2, y1, y2, hash[i + 1]);
    } else if (t == 2) {
      int j;
      cin >> j, j--;
      auto &[x1, y1, x2, y2] = qs[j];
      seg.modify(x1, x2, y1, y2, MOD - hash[j + 1]);
    } else {
      ll x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      x1 /= 2, y1 /= 2, x2 /= 2, y2 /= 2;
      // x1--, y1--, x2--, y2--;
      auto t1 = seg.query(x1, y1);
      auto t2 = seg.query(x2, y2);
      cout << t1 << " " << t2 << "\n";
      // if (t1 == t2) {
      //   cout << "Y";
      // } else {
      //   cout << "N";
      // }
    }
  }
  // cout << "\n";
}
