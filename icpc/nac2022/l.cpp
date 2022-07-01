#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAX = 50;

using Node = multiset<pair<int, int>>;

Node pull(const Node &a, const Node &b, int y1, int y2) {
  auto upper = pair{y2, 0};
  auto c = Node();
  auto f = [&](const Node &t) {
    auto it = t.lower_bound({y1, 0});
    while (c.size() < MAX && it != t.end() && *it < upper) {
      c.insert(*it), it++;
    }
  };
  f(a), f(b);
  return c;
}

struct SegTree {
  int n;
  vector<Node> t;
  SegTree(int _n) : n(_n), t(2 * n){};
  void modify(int p, int y, int h) {
    for (p += n; p; p /= 2) t[p].insert({y, h});
  };
  Node query(int l, int r, int y1, int y2) {
    Node left, right;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) left = pull(left, t[l++], y1, y2);
      if (r & 1) right = pull(t[--r], right, y1, y2);
    }
    return pull(left, right, y1, y2);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> compress;
  compress.reserve(2 * n + 4 * q);
  vector<array<int, 3>> tree(n);
  for (auto &[x, y, h] : tree) {
    cin >> x >> y >> h, compress.push_back(x), compress.push_back(y);
  }
  vector<array<int, 4>> query(q);
  for (auto &[x1, y1, x2, y2] : query) {
    cin >> x1 >> y1 >> x2 >> y2;
    compress.push_back(x1), compress.push_back(y1);
    compress.push_back(x2), compress.push_back(y2);
  }
  sort(compress.begin(), compress.end());
  compress.erase(unique(compress.begin(), compress.end()), compress.end());
  int sz = int(compress.size());
  SegTree seg(sz);
  auto get = [&](int x) {
    return int(lower_bound(compress.begin(), compress.end(), x) - compress.begin());
  };
  for (auto &[x, y, h] : tree) {
    x = get(x), y = get(y);
    seg.modify(x, y, h);
  }
  for (auto &[x1, y1, x2, y2] : query) {
    x1 = get(x1), y1 = get(y1);
    x2 = get(x2), y2 = get(y2);
    auto st = seg.query(x1, x2 + 1, y1, y2 + 1);
    if (st.size() > 44) {
      cout << "1\n";
    } else {
      vector<int> t;
      t.reserve(st.size());
      for (auto &[y, h] : st) t.push_back(h);
      sort(t.begin(), t.end());
      cout << ([&] {
        for (int i = 0; i < int(t.size()) - 2; i++) {
          if (t[i] + t[i + 1] > t[i + 2]) return true;
        }
        return false;
      }()
                   ? "1\n"
                   : "0\n");
    }
  }
}
