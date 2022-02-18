#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

ll pull(ll a, ll b) { return a + b; }

struct SegTree {
  ll n;
  vector<ll> t;
  SegTree(ll _n) : n(_n), t(2 * n){};
  void modify(ll p, const ll &v) {
    t[p += n] += v;
    for (p /= 2; p; p /= 2) t[p] = pull(t[p * 2], t[p * 2 + 1]);
  }
  ll query(ll l, ll r) {
    ll left = 0, right = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) left = pull(left, t[l++]);
      if (r & 1) right = pull(t[--r], right);
    }
    return pull(left, right);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q;
  cin >> n >> q;
  ll s = ll(sqrt(n)) + 1;
  SegTree seg(n);
  vector<vector<ll>> pre(s, vector<ll>(s));
  while (q--) {
    ll op, x, y;
    cin >> op >> x >> y, x--;
    if (op == 1) {
      seg.modify(x, y);
    } else if (op == 2) {
      ll len;
      cin >> len;
      seg.modify(x, -y);
      x %= len;
      if (len >= s) {
        for (ll i = x; i < n; i += len) seg.modify(i, y);
      } else {
        for (ll i = x; i < len; i++) {
          pre[len][i + 1] += y;
        }
      }
    } else {
      auto get_block = [&](ll t) {
        ll ans = 0;
        for (int i = 1; i < s; i++) {
          ans += t / i * pre[i][i];
          ans += pre[i][t % i];
        }
        return ans;
      };
      ll res = seg.query(x, y);
      cout << res + get_block(y) - get_block(x) << "\n";
    }
  }
}
