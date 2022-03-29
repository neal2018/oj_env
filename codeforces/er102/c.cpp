#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

struct SegTree {
  ll n;
  vector<int> t;
  SegTree(ll _n) : n(_n), t(2 * n) {}
  void modify(ll p, int v) {
    t[p += n] += v;
    for (p /= 2; p; p /= 2) t[p] = t[2 * p] + t[2 * p + 1];
  }
  int query(ll l, ll r) {
    int res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l &    1) res += t[l++];
      if (r & 1) res += t[--r];
    }
    return res;
  }
};

ll get_inversion(vector<ll> a) {
  auto compress = a;
  sort(compress.begin(), compress.end());
  compress.erase(unique(compress.begin(), compress.end()), compress.end());
  for (auto& x : a) x = lower_bound(compress.begin(), compress.end(), x) - compress.begin();
  ll res = 0, sz = compress.size();
  SegTree seg(sz);
  for (auto& x : a) {
    res += seg.query(x, sz);
    seg.modify(x, 1);
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      if (i < k) {
        a[i] = i + 1;
      } else {
        a[i] = k - (i - k + 1);
      }
    }
    ll inv = 0;
    SegTree seg(k + 1);
    for (int i = 0; i < n; i++) {
      inv += seg.query(a[i], k + 1);
      seg.modify(a[i], 1);
    }
    set<pair<ll, ll>> st;
    for (int i = 0; i < n; i++) {
      st.insert({a[i], i});
    }
    vector<ll> res(n);
    for (int i = 0; i < n; i++) {
      if (inv >= st.size()) {
        auto [v, pos] = *st.rbegin();
        res[i] = pos;
        st.erase(--st.end());
      } else if (inv) {
      } else {
      }
    }
  };
}
