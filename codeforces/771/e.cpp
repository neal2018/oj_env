#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

struct SegTree {
  int n;
  vector<ll> t;
  SegTree(int _n) : n(_n), t(2 * n) {}
  void apply(ll x, ll v) { t[x] += v; }
  void modify(ll l, ll r, ll v) {
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
    }
  }
  ll query(ll p) {
    ll res = t[p += n];
    for (p /= 2; p > 0; p /= 2) res += t[p];
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  SegTree seg(n);
  vector<ll> color(n);
  map<ll, ll> mp;
  mp[0] = 0, mp[n] = 0;
  auto split = [&](ll x) { mp[x] = (--mp.upper_bound(x))->second; };
  while (q--) {
    string op;
    cin >> op;
    if (op == "Color") {
      ll l, r, c;
      cin >> l >> r >> c, l--, c--;
      split(l), split(r);
      auto it = mp.find(l);
      while (it->first < r) {
        seg.modify(it->first, next(it)->first, color[it->second] - color[c]);
        it = mp.erase(it);
      }
      mp[l] = c;
    } else if (op == "Add") {
      ll c, x;
      cin >> c >> x, c--;
      color[c] += x;
    } else {
      ll x;
      cin >> x, x--;
      auto it = --mp.upper_bound(x);
      cout << seg.query(x) + color[it->second] << "\n";
    }
  }
}
