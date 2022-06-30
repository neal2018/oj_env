#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e18;

struct Node {
  ll maxi_v = 0, maxi_id = 0, mini_v = inf, mini_id = 0, init = 0;
};

Node pull(const Node &a, const Node &b) {
  if (!a.init) return b;
  if (!b.init) return a;
  Node c = a;
  if (b.maxi_v > c.maxi_v) c.maxi_v = b.maxi_v, c.maxi_id = b.maxi_id;
  if (b.mini_v < c.mini_v) c.mini_v = b.mini_v, c.mini_id = b.mini_id;
  return c;
}

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
  const double INF = 1.0 / 0.0;
  cout << INF << "\n";
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x, x--;
    SegTree seg(n);
    for (int i = 0; i < n; i++) seg.t[i + n] = {a[i], i, a[i], i, 1};
    for (int i = n - 1; i >= 0; i--) seg.t[i] = pull(seg.t[2 * i], seg.t[2 * i + 1]);
    vector<ll> dp(n);
    for (int i = 1; i < n; i++) {
      dp[i] = dp[i - 1] + 1;
      auto left = [&] {
        auto check = [&](ll mid) {
          auto node = seg.query(mid, i + 1);
          return node.maxi_id == i || node.mini_id == i;
        };
        ll l = 0, r = i - 1;
        while (l < r) {
          ll mid = (l + r) / 2;
          if (check(mid)) {
            r = mid;
          } else {
            l = mid + 1;
          }
        }
        return r;
      }();
      auto node = seg.query(left, i + 1);
      ll pre = node.mini_id == i ? node.maxi_id : node.mini_id;
      dp[i] = min(dp[i], dp[pre] + 1);
    }
    cout << dp[n - 1] << "\n";
  }
}
