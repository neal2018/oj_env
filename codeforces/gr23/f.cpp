#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 33;

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
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<array<int, 3>> queries(q);
  int res_cnt = 0;
  auto compress = a;
  for (auto& v : queries) {
    int t;
    cin >> t;
    if (t == 1) {
      int i, x;
      cin >> i >> x, i--, v = {i, x, -1}, compress.push_back(x);
    } else {
      int l, r, k;
      cin >> l >> r >> k, l--, v = {l, r, k};
      res_cnt++;
    }
  }
  sort(compress.begin(), compress.end());
  compress.erase(unique(compress.begin(), compress.end()), compress.end());
  for (auto& x : a) x = int(lower_bound(compress.begin(), compress.end(), x) - compress.begin());
  for (auto& [i, x, k] : queries) {
    if (k == -1) x = int(lower_bound(compress.begin(), compress.end(), x) - compress.begin());
  }
  vector<int> res(res_cnt, 1);
  for (int _ = 0; _ < 40; _++) {
    vector<ll> hash(compress.size());
    for (auto& x : hash) x = rng() % MOD;
    SegTree seg(n);
    for (int i = 0; i < n; i++) seg.t[i + n] = hash[a[i]];
    for (int i = n - 1; i; i--) seg.t[i] = seg.t[i * 2] + seg.t[i * 2 + 1];
    int cnt = 0;
    for (auto& v : queries) {
      if (v[2] == -1) {
        seg.modify(v[0], hash[v[1]]);
      } else {
        auto s = seg.query(v[0], v[1]);
        if (s % v[2] != 0) res[cnt] = 0;
        cnt++;
      }
    }
  }
  for (auto& x : res) cout << (x ? "YES\n" : "NO\n");
}
