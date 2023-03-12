#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

struct Node {
  ll v = inf, init = 0;
};

Node pull(const Node& a, const Node& b) {
  if (!a.init) return b;
  if (!b.init) return a;
  return {min(a.v, b.v), 1};
}

struct SegTree {
  ll n;
  vector<Node> t;
  SegTree(ll _n) : n(_n), t(2 * n, {inf, 1}){};
  void modify(ll p, const Node& v) {
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
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), cold(k), hot(k);
    for (auto& x : a) cin >> x, x--;
    for (auto& x : cold) cin >> x;
    for (auto& x : hot) cin >> x;
    SegTree dp(k + 1);
    dp.modify(k, {0, 1});
    ll all = 0;
    for (int id = 0; id < n; id++) {
      auto x = a[id];
      // vector<ll> ndp(k + 1, inf);

      // other one
      int prev = id == 0 ? k : a[id - 1];
      // for (int i = 0; i <= k; i++) {
      //   if (i == x) {
      //     ndp[prev] = min(ndp[prev], dp[i] + hot[x]);
      //   } else {
      //     ndp[prev] = min(ndp[prev], dp[i] + cold[x]);
      //   }
      // }
      ll addon = (prev == x ? hot[x] : cold[x]);
      {
        auto node = dp.query(0, k + 1);
        auto val = node.v + cold[x];
        val = min(val, dp.query(x, x + 1).v + hot[x]);
        dp.modify(prev, {val - addon, 1});
      }

      // i-1 one
      // for (int i = 0; i <= k; i++) {
      //   if (prev == x) {
      //     ndp[i] = min(ndp[i], dp[i] + hot[x]);
      //   } else {
      //     ndp[i] = min(ndp[i], dp[i] + cold[x]);
      //   }
      // }
      // swap(ndp, dp);
      all += addon;
    }
    auto res = dp.query(0, k + 1).v + all;
    cout << res << "\n";
  }
}
