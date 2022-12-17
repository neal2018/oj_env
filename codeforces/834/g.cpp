#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
  int sum = 0, mini = 0, pos = 0, init = 0;
};

Node pull(const Node &a, const Node &b) {
  if (!a.init) return b;
  if (!b.init) return a;
  Node c{a.sum + b.sum, min(a.mini, a.sum + b.mini), (a.mini < a.sum + b.mini) ? a.pos : b.pos, 1};
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
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> b(n / 2);
    for (auto &x : b) cin >> x, x--;
    vector<int> t(n, 1);
    for (auto &x : b) t[x] = -1;
    SegTree seg(n);
    for (int i = 0; i < n; i++) seg.t[i + n] = {t[i], min(0, t[i]), i + (t[i] < 0), 1};
    for (int i = n - 1; i; i--) seg.t[i] = pull(seg.t[i * 2], seg.t[i * 2 + 1]);

    if (set(b.begin(), b.end()).size() != n / 2 || seg.query(0, n).mini < 0) {
      cout << "-1\n";
      continue;
    }

    for (int i = 0; i < n / 2; i++) {
      auto node = seg.query(0, b[i]);
      int pos = node.pos;
      seg.modify(pos, {0, 0, pos, 0});
      seg.modify(b[i], {0, 0, b[i], 0});
      cout << pos + 1 << " " << b[i] + 1 << " ";
    }
    cout << "\n";
  }
}
