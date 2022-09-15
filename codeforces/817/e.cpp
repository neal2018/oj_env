#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

constexpr int MAX = 1001;

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<SegTree> trees(MAX, SegTree(MAX));
    for (ll i = 0, h, w; i < n; i++) {
      cin >> h >> w;
      trees[h].modify(w, h * w);
    }
    while (q--) {
      ll hs, ws, hb, wb;
      cin >> hs >> ws >> hb >> wb;
      ll res = 0;
      for (ll h = hs + 1; h < hb; h++) {
        res += trees[h].query(ws + 1, wb);
      }
      cout << res << "\n";
    }
  }
}
