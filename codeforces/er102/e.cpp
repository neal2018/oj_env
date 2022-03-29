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
  vector<array<int, 3>> v, h;
  vector<int> compress;
  compress.reserve(n * 3);
  for (int i = 0, x1, y1, x2, y2; i < n; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (y1 == y2) {
      h.push_back({y1, min(x1, x2), max(x1, x2)});
      compress.push_back(y1);
      compress.push_back(x1);
      compress.push_back(x2);
    } else {
      v.push_back({x1, min(y1, y2), max(y1, y2)});
      compress.push_back(x1);
      compress.push_back(y1);
      compress.push_back(y2);
    }
  }
  ll vsz = v.size(), hsz = h.size();
  sort(h.begin(), h.end());
  sort(v.begin(), v.end());
  sort(compress.begin(), compress.end());
  compress.erase(unique(compress.begin(), compress.end()), compress.end());
  ll MAX = compress.size();
  for (auto& [a, b, c] : h) {
    a = int(lower_bound(compress.begin(), compress.end(), a) - compress.begin());
    b = int(lower_bound(compress.begin(), compress.end(), b) - compress.begin());
    c = int(lower_bound(compress.begin(), compress.end(), c) - compress.begin());
  }
  for (auto& [a, b, c] : v) {
    a = int(lower_bound(compress.begin(), compress.end(), a) - compress.begin());
    b = int(lower_bound(compress.begin(), compress.end(), b) - compress.begin());
    c = int(lower_bound(compress.begin(), compress.end(), c) - compress.begin());
  }
  vector<vector<int>> cross(hsz);
  for (int i = 0; i < hsz; i++) {
    for (int j = 0; j < vsz; j++) {
      auto [yh, xh1, xh2] = h[i];
      auto [xv, yv1, yv2] = v[j];
      if (xh1 <= xv && xv <= xh2 && yv1 <= yh && yh <= yv2) {
        cross[i].push_back(j);
      }
    }
  }
  ll res = 0;
  constexpr ll HASH = 100000;
  vector<ll> cnt(hsz);
  for (int i = 0; i < hsz; i++) {
    vector<ll> qs;
    qs.reserve(2 * hsz + cross[i].size());
    for (auto& c : cross[i]) {
      auto [xv, yv1, yv2] = v[c];
      qs.push_back(xv * HASH * HASH + 1 * HASH + yv2);
    }
    for (int j = i + 1; j < hsz; j++) {
      auto [yh, xh1, xh2] = h[j];
      cnt[j] = 0;
      qs.push_back(xh2 * HASH * HASH + 2 * HASH + j);
    }
    sort(qs.begin(), qs.end());
    SegTree seg(MAX);
    for (auto& tt : qs) {
      ll is_q = (tt % (HASH * HASH)) / HASH;
      ll y = tt % HASH;
      if (is_q == 1) {
        seg.modify(y, 1);
      } else {
        auto [yh, xh1, xh2] = h[y];
        ll temp = seg.query(yh, MAX);
        if (is_q == 0) {
          cnt[y] -= temp;
        } else {
          cnt[y] += temp;
        }
      }
    }
    for (int j = i + 1; j < hsz; j++) {
      res += (cnt[j] - 1) * cnt[j] / 2;
    }
  }
  cout << res << "\n";
}
