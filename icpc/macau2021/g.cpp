#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e18;

struct Node {
  ll v = inf;
};

Node pull(const Node &a, const Node &b) { return {min(a.v, b.v)}; }

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
    int n, k;
    cin >> n >> k;
    vector<int> pos(n);
    for (int i = 0, x; i < n; i++) cin >> x, pos[x] = i;
    vector<ll> at_1(n, inf), at_k(n, inf);
    SegTree seg(n);
    auto get = [&](int l, int r) {  // [ , )
      if (l < r) {
        return min(seg.query(0, l).v, seg.query(r, n).v);
      } else {
        return seg.query(r, l).v;
      }
    };
    auto dist = [&](int l, int r) {
      l = (l + n) % n, r = (r + n) % n;
      return min(abs(l - r), n - abs(l - r));
    };
    for (int val = n - 1; val >= 0; val--) {
      int p = pos[val];
      at_1[val] = get(p, (p + k - 1) % n + 1);
      at_k[val] = get((p - k + 1 + n) % n, p + 1);
      seg.modify(p, {val});
    }
    vector<ll> dp_1(n, inf), dp_k(n, inf);
    ll t = 0;
    for (; t < n && pos[t] < k; t++) {
    }
    if (t >= n) {
      cout << "0\n";
      continue;
    }
    dp_1[t] = dist(0, pos[t]), dp_k[t] = dist(k - 1, pos[t]);
    ll res = inf;
    for (int i = 0; i < n; i++) {
      if (dp_1[i] < inf) {
        if (at_1[i] >= n) {
          res = min(res, dp_1[i]);
        } else {
          dp_1[at_1[i]] = min(dp_1[at_1[i]], dp_1[i] + dist(pos[at_1[i]], pos[i]));
          dp_k[at_1[i]] = min(dp_k[at_1[i]], dp_1[i] + dist(pos[at_1[i]], pos[i] + k - 1));
        }
      }
      if (dp_k[i] < inf) {
        if (at_k[i] >= n) {
          res = min(res, dp_k[i]);
        } else {
          dp_1[at_k[i]] = min(dp_1[at_k[i]], dp_k[i] + dist(pos[at_k[i]], pos[i] - k + 1));
          dp_k[at_k[i]] = min(dp_k[at_k[i]], dp_k[i] + dist(pos[at_k[i]], pos[i]));
        }
      }
    }
    cout << res << "\n";
  }
}
