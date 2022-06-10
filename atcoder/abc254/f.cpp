#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
  ll n;
  vector<ll> t;
  SegTree(ll _n) : n(_n), t(2 * n) {}
  void modify(ll p, ll v) {
    t[p += n] += v;
    for (p /= 2; p; p /= 2) t[p] = t[2 * p] + t[2 * p + 1];
  }
  ll query(ll l, ll r) {
    ll res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res = gcd(res, t[l++]);
      if (r & 1) res = gcd(res, t[--r]);
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<ll> a(n), b(n);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;
  SegTree seg_a(n), seg_b(n);
  for (int i = 1; i < n; i++) seg_a.t[i + n] = a[i] - a[i - 1];
  for (int i = 1; i < n; i++) seg_b.t[i + n] = b[i] - b[i - 1];
  for (int i = n - 1; i; i--) seg_a.t[i] = gcd(seg_a.t[i * 2], seg_a.t[i * 2 + 1]);
  for (int i = n - 1; i; i--) seg_b.t[i] = gcd(seg_b.t[i * 2], seg_b.t[i * 2 + 1]);
  while (q--) {
    int h1, h2, w1, w2;
    cin >> h1 >> h2 >> w1 >> w2, h1--, h2--, w1--, w2--;
    cout << gcd(a[h1] + b[w1], gcd(seg_a.query(h1 + 1, h2 + 1), seg_b.query(w1 + 1, w2 + 1)))
         << "\n";
  }
}
