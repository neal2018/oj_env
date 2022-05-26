#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct Node {
  ll v = 0, cnt = 0;
};

Node pull(const Node &a, const Node &b) { return {a.v + b.v, a.cnt + b.cnt}; }

struct SegTree {
  ll n;
  vector<Node> t;
  SegTree(ll _n) : n(_n), t(2 * n){};
  void modify(ll p, const Node &v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = pull(t[p * 2], t[p * 2 + 1]);
  }
  Node query(ll l, ll r) {
    Node left, right;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) left = pull(left, t[l++]);
      if (r & 1) right = pull(t[--r], right);
    }
    return pull(left, right);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll, ll> freq;
    for (auto &x : a) cin >> x, freq[x]++;
    vector<pair<ll, ll>> b(freq.begin(), freq.end());
    sort(b.begin(), b.end(), [](const auto &x, const auto &y) { return x.second < y.second; });
    map<ll, ll> val2order;
    SegTree seg(b.size());
    for (int i = 0; i < b.size(); i++) {
      val2order[b[i].first] = i;
      seg.modify(i, {b[i].second, 1});
    }

    ll empty = 0, res = 1e18;
    for (int mex = 0; mex <= n; mex++) {
      if (empty > k) break;
      auto total = seg.query(0, b.size());
      ll l = 0, r = b.size();
      while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (seg.query(0, mid).v <= k) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      auto node = seg.query(0, l);
      res = min(res, total.cnt - node.cnt);
      if (val2order.count(mex)) {
        seg.modify(val2order[mex], {0, 0});
      }
      empty += freq.count(mex) == 0;
    }
    cout << res << "\n";
  }
}
