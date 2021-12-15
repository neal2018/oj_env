#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct SegTree {
  ll n, h = 0;
  vector<ll> t, lazy;

  SegTree(ll _n) : n(_n), h((ll)log2(n)), t(n * 2), lazy(n * 2) {}

  void apply(ll x, ll v, ll k) {
    t[x] = v * k;
    if (x < n) lazy[x] = v;
  }

  void build(ll l) {
    ll k = 2;
    for (l = (l + n) / 2; l > 0; k <<= 1, l >>= 1) {
      if (lazy[l]) {
        t[l] = lazy[l] * k;
      } else {
        t[l] = t[l * 2] + t[l * 2 + 1];
      }
    }
  }

  void push(ll l) {
    l += n;
    for (ll s = h; s > 0; s--) {
      ll i = l >> s;
      if (lazy[i] == 0) continue;
      apply(2 * i, lazy[i], 1 << (s - 1));
      apply(2 * i + 1, lazy[i], 1 << (s - 1));
      lazy[i] = 0;
    }
  }

  void modify(ll l, ll r, ll v) {
    push(l), push(r - 1);
    ll l0 = l, r0 = r, k = 1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
      if (l & 1) apply(l++, v, k);
      if (r & 1) apply(--r, v, k);
    }
    build(l0), build(r0 - 1);
  }

  ll query(ll l, ll r) {
    push(l), push(r - 1);
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res += t[l++];
      if (r & 1) res += t[--r];
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, q;
  string s, f;
  auto func = [&]() {
    cin >> n >> q;
    cin >> s >> f;
    vector<pair<int, int>> query(q);
    for (int l, r, i = 0; i < q; i++) {
      cin >> l >> r;
      query[i] = {--l, r};
    }
    reverse(query.begin(), query.end());
    SegTree seg(n);
    for (int i = 0; i < n; i++) {
      if (f[i] == '0') {
        seg.t[i + n] = 1;
      } else {
        seg.t[i + n] = 2;
      }
    }
    for (int i = n - 1; i > 0; i--) {
      seg.t[i] = seg.t[i * 2] + seg.t[i * 2 + 1];
    }
    for (auto& [l, r] : query) {
      ll sum = seg.query(l, r) - (r - l);  // number of 2
      if (sum == 0 || sum == r - l) continue;
      if (sum * 2 == r - l) return false;
      if (sum * 2 < r - l) {
        seg.modify(l, r, 1);
      } else {
        seg.modify(l, r, 2);
      }
    }
    string res = f;
    for (int i = 0; i < n; i++) {
      if (seg.query(i, i + 1) == 2) {
        res[i] = '1';
      } else {
        res[i] = '0';
      }
    }
    return res == s;
  };
  cin >> T;
  while (T--) cout << (func() ? "YES\n" : "NO\n");
}
