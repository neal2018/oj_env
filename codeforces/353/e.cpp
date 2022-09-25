#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
  ll v = -1, id = -1;
  auto operator<=>(const Node &) const = default;  // need c++ 20
};

Node pull(const Node &a, const Node &b) { return max(a, b); }

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
  int n;
  cin >> n;
  vector<int> a(n, n - 1);
  for (int i = 0; i < n - 1; i++) cin >> a[i], a[i]--;
  SegTree seg(n);
  for (int i = 0; i < n; i++) seg.t[i + n] = {a[i], i};
  for (int i = n - 1; i; i--) seg.t[i] = pull(seg.t[i * 2], seg.t[i * 2 + 1]);
  vector<ll> dp(n);
  ll res = 0;
  for (int i = n - 2; i >= 0; i--) {
    auto maxi = seg.query(i + 1, a[i] + 1).id;
    dp[i] = dp[maxi] - (a[i] - maxi) + n - i - 1;
    res += dp[i];
  }
  cout << res << "\n";
}
