#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

struct Node {
  ll sum = 0, total = 0, cnt = 0, cnt_total = 0, flip = 0;  // child
  // cnt: odd point
};

Node pull(const Node &a, const Node &b) {
  return {a.sum + b.sum, a.total + b.total, a.cnt + b.cnt, a.cnt_total + b.cnt_total};
}

struct SegTree {
  ll n, h = 0;
  vector<Node> t;
  vector<ll> total;
  SegTree(ll _n) : n(_n), h((ll)log2(n)), t(n * 2), total(n * 2) {}
  void build(vector<ll> &compressed) {
    for (int i = n; i < 2 * n - 1; i++) total[i] = compressed[i - n + 1] - compressed[i - n];
    for (int i = n - 1; i > 0; i--) total[i] = total[2 * i] + total[2 * i + 1];
  }
  void apply(ll x, ll v) {
    if (v == 0) return;
    t[x].sum = total[x] - t[x].sum;
    t[x].flip ^= 1;
  }
  void build(ll l) {
    for (l = (l + n) / 2; l > 0; l /= 2) {
      ll tag = t[l].flip;
      t[l] = pull(t[l * 2], t[l * 2 + 1]);
      if (tag) apply(l, tag);
    }
  }
  void push(ll l) {
    l += n;
    for (ll s = h; s > 0; s--) {
      ll i = l >> s;
      if (t[i].flip != 0) {
        apply(2 * i, t[i].flip);
        apply(2 * i + 1, t[i].flip);
      }
      t[i].flip = 0;
    }
  }
  void modify(ll l, ll r, ll v) {
    push(l), push(r - 1);
    ll l0 = l, r0 = r;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
    }
    build(l0), build(r0 - 1);
  }
  Node query(ll l, ll r) {
    push(l), push(r - 1);
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
  ll nn;
  cin >> nn;
  map<ll, vector<array<ll, 3>>> xs;
  vector<ll> compressed;
  for (int i = 0; i < nn; i++) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    compressed.push_back(y1), compressed.push_back(y2);
    xs[x1].push_back({y1, y2, 1}), xs[x2].push_back({y1, y2, -1});
  }
  sort(compressed.begin(), compressed.end());
  compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());
  int n = compressed.size();
  unordered_map<ll, int> id(n);
  id.reserve(1024);
  for (int i = 0; i < n; i++) id[compressed[i]] = i;
  SegTree seg(n);
  seg.build(compressed);
  ll res = 0;
  for (auto it1 = xs.begin(), it2 = ++xs.begin(); it2 != xs.end(); it1++, it2++) {
    for (auto &v : it1->second) seg.modify(id[v[0]], id[v[1]], 1);
    res += seg.query(0, n).sum * (it2->first - it1->first);
  }
  cout << res << "\n";
}
