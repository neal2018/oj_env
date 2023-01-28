#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
  ll n;
  vector<ll> t;
  SegTree(ll _n) : n(_n), t(2 * n) {}
  void modify(ll p, ll v) {
    t[p += n] = v;
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
  int n;
  cin >> n;
  vector<array<ll, 2>> a(n);
  for (auto& [x, y] : a) cin >> x >> y;
  int q;
  cin >> q;

  vector<ll> compress;
  compress.reserve(n + q);
  for (auto& [x, y] : a) compress.push_back(x);

  vector<array<ll, 3>> queries(q);
  for (auto& [x, y, z] : queries) {
    cin >> x >> y, z = -1;
    if (x != 3) cin >> z, y--;
    if (x == 1) compress.push_back(z);
  }
  sort(compress.begin(), compress.end());
  compress.erase(unique(compress.begin(), compress.end()), compress.end());
  // for (auto& x : a) x = lower_bound(compress.begin(), compress.end(), x) - compress.begin();
  map<ll, ll> mapping;
  int total = int(compress.size());
  for (int i = 0; i < total; i++) mapping[compress[i]] = i;
  vector<ll> quota(total);
  for (auto [x, y] : a) {
    quota[mapping[x]] += y;
  }
  SegTree seg(total);
  SegTree seg2(total);
  for (int i = 0; i < total; i++) seg.t[i + total] += compress[i] * quota[i];
  for (int i = total - 1; i >= 0; i--) seg.t[i] = seg.t[2 * i] + seg.t[2 * i + 1];

  for (int i = 0; i < total; i++) seg2.t[i + total] += quota[i];
  for (int i = total - 1; i >= 0; i--) seg2.t[i] = seg2.t[2 * i] + seg2.t[2 * i + 1];

  for (auto& [t, x, y] : queries) {
    if (t == 1) {
      auto [os, oq] = a[x];
      auto com_os = mapping[os];
      quota[com_os] -= oq;
      seg.modify(com_os, os * quota[com_os]);
      seg2.modify(com_os, quota[com_os]);

      auto com_ns = mapping[y];
      quota[com_ns] += oq;
      seg.modify(com_ns, y * quota[com_ns]);
      seg2.modify(com_ns, quota[com_ns]);

      a[x][0] = y;
    } else if (t == 2) {
      auto [os, oq] = a[x];
      auto com_os = mapping[os];
      quota[com_os] -= oq;
      quota[com_os] += y;
      seg.modify(com_os, os * quota[com_os]);
      seg2.modify(com_os, quota[com_os]);
      a[x][1] = y;
    } else {
      int l = 0, r = total;
      while (l < r) {
        int mid = (l + r) / 2;
        if (seg2.query(mid, total) > x) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      // [l, total] <= x
      ll cur = seg2.query(l, total);
      ll res = seg.query(l, total);
      ll remain = x - cur;
      if (l > 0) {
        res += remain * compress[l - 1];
        remain = 0;
      }
      if (remain > 0) res = -1;
      cout << res << "\n";
    }
  }
}