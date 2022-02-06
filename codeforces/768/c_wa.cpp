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
    for (p /= 2; p; p /= 2) t[p] = max(t[2 * p], t[2 * p + 1]);
  }
  ll query(ll l, ll r) {
    ll res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res = max(res, t[l++]);
      if (r & 1) res = max(res, t[--r]);
    }
    return res;
  }
};

struct SegTree2 {
  ll n;
  vector<ll> t;
  SegTree2(ll _n) : n(_n), t(2 * n) {}
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x, x--;
  ll res = 0;
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) mp[a[i]].push_back(i);
  vector<pair<int, int>> inter;
  SegTree2 minus(n);
  for (auto& [k, v] : mp) {
    int ttt = (int)v.size();
    res += max(0, ttt - 2);
    for (int i = 0; i < ttt - 1; i++) {
      inter.push_back({v[i], v[i + 1] + 1});  //[, )
      if (i != ttt - 2) {
        minus.modify(v[i + 1], 1);
      }
    }
  }
  sort(inter.begin(), inter.end(),
       [&](const pair<int, int>& x, const pair<int, int>& y) { return x.second < y.second; });
  SegTree seg(inter.size());
  for (int i = 0; i < inter.size(); i++) {
    auto [l, r] = inter[i];
    auto it = upper_bound(
        inter.begin(), inter.end(), pair{0, l},
        [&](const pair<int, int>& x, const pair<int, int>& y) { return x.second < y.second; });
    ll tt = it - inter.begin();
    ll cur = seg.query(0, tt);
    cur += r - l - 2 - minus.query(l + 1, r - 1);
    seg.modify(i, cur);
  }
  cout << seg.query(0, inter.size()) + res << "\n";
}