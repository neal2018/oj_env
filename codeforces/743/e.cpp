#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

constexpr int MAX = 1ll << 30;

struct Node {
  int init = 0;
  int v[31];
  Node(int x = MAX) {
    init = 1, v[0] = x;
    for (int i = 1; i < 31; i++) v[i] = MAX;
  }
};

Node pull(const Node &a, const Node &b) {
  if (!a.init) return b;
  if (!b.init) return a;
  Node c;
  for (int i = 0, j = 0; i + j < 31;) {
    if (a.v[i] < b.v[j]) {
      c.v[i + j] = a.v[i], i++;
    } else {
      c.v[i + j] = b.v[j], j++;
    }
  }
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
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> ver(n + 1);
    SegTree seg(n);
    for (int i = 0; i < n; i++) {
      seg.t[i + n] = Node(a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
      seg.t[i] = pull(seg.t[i * 2], seg.t[i * 2 + 1]);
    }
    int q;
    cin >> q;
    while (q--) {
      int l, r;
      cin >> l >> r, l--;
      auto node = seg.query(l, r);
      int mini = MAX;
      for (int i = 0; i < 31; i++) {
        for (int j = i + 1; j < 31; j++) mini = min(mini, node.v[i] | node.v[j]);
      }
      cout << mini << "\n";
    }
  }
}
