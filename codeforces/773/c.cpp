#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

template <typename Node, auto pull, auto init = 0>
struct SegTree {
  ll n;
  vector<Node> t;
  SegTree(ll _n) : n(_n), t(2 * n, init){};
  void modify(ll p, const Node &v) {
    p += n;
    t[p] = pull(t[p], v);
    for (p /= 2; p; p /= 2) t[p] = pull(t[p * 2], t[p * 2 + 1]);
  }
  Node query(ll l, ll r) {
    Node left = init, right = init;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) left = pull(left, t[l++]);
      if (r & 1) right = pull(t[--r], right);
    }
    return pull(left, right);
  }
};

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  SegTree<ll, [](ll x, ll y) { return min(x, y); }, inf> seg(n);
  set<ll> st;
  for (int i = -1; i <= n; i++) st.insert(i);
  while (q--) {
    ll op;
    cin >> op;
    if (op == 0) {
      ll l, r, x;
      cin >> l >> r >> x, l--;
      if (x == 0) {
        auto it = st.lower_bound(l);
        while (*it < r) it = st.erase(it);
      } else {
        seg.modify(l, r);
      }
    } else {
      ll x;
      cin >> x, x--;
      if (!st.count(x)) {
        cout << "NO\n";
      } else {
        auto it = st.find(x);
        ll l = *prev(it);
        ll r = *next(it);
        ll mini = seg.query(l + 1, x + 1);
        if (mini <= r) {
          cout << "YES\n";
        } else {
          cout << "N/A\n";
        }
      }
    }
  }
}
