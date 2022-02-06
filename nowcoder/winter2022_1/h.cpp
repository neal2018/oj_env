#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

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
      if (l & 1) res += t[l++];
      if (r & 1) res += t[--r];
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, res = 0, N = 1000;
  cin >> n;
  SegTree seg(N + 1);
  SegTree count(N + 1);
  for (ll i = 0, x; i < n; i++) {
    cin >> x;
    seg.modify(x, x);
    count.modify(x, 1);
    ll l_sum = seg.query(0, N - x);
    ll l_cnt = count.query(0, N - x);
    ll r_sum = seg.query(N - x, N + 1);
    ll r_cnt = count.query(N - x, N + 1);
    res += N * l_cnt - x * l_cnt - l_sum;
    res += -N * r_cnt + x * r_cnt + r_sum;
  }
  cout << res << "\n";
}