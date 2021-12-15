#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct SegTree {
  ll n;
  vector<int> t;
  SegTree(ll _n) : n(_n) { t.resize(2 * n); }
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
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;
  auto bb = b;
  sort(bb.begin(), bb.end());
  bb.erase(unique(bb.begin(), bb.end()), bb.end());
  map<ll, ll> bmp;
  for (int i = 0; i < bb.size(); i++) bmp[bb[i]] = i;
  for (auto& x : b) x = bmp[x];
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int x, int y) { return a[x] < a[y]; });
  ll sz = bb.size();
  SegTree seg(sz);
  ll res = 0, r = 0;
  for (ll i = 0; i < n; i = r) {
    r = i + 1;
    while (r < n && a[p[r]] == a[p[r - 1]]) r++;
    for (ll j = i; j < r; j++) seg.modify(b[p[j]], 1);
    for (ll j = i; j < r; j++) res += seg.query(b[p[j]], sz);
  }
  cout << res << '\n';
}
