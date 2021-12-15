#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
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
  int T;
  cin >> T;
  while (T--) {
    int n, can = 0;
    ll ans = 0;
    cin >> n;
    SegTree seg(n);
    set<ll> st;
    for (int i = 0, x; i < n; i++) {
      cin >> x, x--;
      ans += seg.query(x + 1, n);
      seg.modify(x, 1);
      if (st.count(x)) {
        can = 1;
      }
      st.insert(x);
    }
    // cout << ans << '\n';
    if (ans % 2 == 0 || can) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}