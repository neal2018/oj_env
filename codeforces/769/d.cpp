#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

struct SegTree {
  ll n;
  vector<ll> t;
  SegTree(ll _n) : n(_n), t(2 * n) {}
  void modify(ll p, ll v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = gcd(t[2 * p], t[2 * p + 1]);
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
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll need = 0;
  SegTree seg(n);
  for (int i = 0; i < n; i++) {
    seg.modify(i, a[i]);
    ll l = 0, r = i;
    while (l < r) {
      ll mid = (l + r) / 2;
      if (seg.query(mid, i + 1) < (i - mid + 1)) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    if (seg.query(r, i + 1) == i - r + 1) {
      seg.modify(i, MOD), need++;
    }
    cout << need << " ";
  }
  cout << "\n";
}
