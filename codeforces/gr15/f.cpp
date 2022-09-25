#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
  Node *l, *r;
  int s, sz;
  int t = 0, a = 0, g = 0;  // for lazy propagation
  ll w;

  Node(int _s) : l(nullptr), r(nullptr), s(_s), sz(1), w(rng()) {}
  void apply(int vt, int vg) {
    // for lazy propagation
    s -= vt;
    t += vt, a += vg, g += vg;
  }
  void push() {
    // for lazy propagation
    if (l != nullptr) l->apply(t, g);
    if (r != nullptr) r->apply(t, g);
    t = g = 0;
  }
  void pull() { sz = 1 + (l ? l->sz : 0) + (r ? r->sz : 0); }
};

pair<Node *, Node *> split(Node *t, int v) {
  if (t == nullptr) return {nullptr, nullptr};
  t->push();
  if (t->s < v) {
    auto [x, y] = split(t->r, v);
    t->r = x;
    t->pull();
    return {t, y};
  } else {
    auto [x, y] = split(t->l, v);
    t->l = y;
    t->pull();
    return {x, t};
  }
}

Node *merge(Node *p, Node *q) {
  if (p == nullptr) return q;
  if (q == nullptr) return p;
  if (p->w < q->w) swap(p, q);
  auto [x, y] = split(q, p->s + rng() % 2);
  p->push();
  p->l = merge(p->l, x);
  p->r = merge(p->r, y);
  p->pull();
  return p;
}

Node *insert(Node *t, int v) {
  auto [x, y] = split(t, v);
  return merge(merge(x, new Node(v)), y);
}

Node *erase(Node *t, int v) {
  auto [x, y] = split(t, v);
  auto [p, q] = split(y, v + 1);
  return merge(merge(x, merge(p->l, p->r)), q);
}

int get_rank(Node *&t, int v) {
  auto [x, y] = split(t, v);
  int res = (x ? x->sz : 0) + 1;
  t = merge(x, y);
  return res;
}

Node *kth(Node *t, int k) {
  k--;
  while (true) {
    int left_sz = t->l ? t->l->sz : 0;
    if (k < left_sz) {
      t = t->l;
    } else if (k == left_sz) {
      return t;
    } else {
      k -= left_sz + 1, t = t->r;
    }
  }
}

Node *get_prev(Node *&t, int v) {
  auto [x, y] = split(t, v);
  Node *res = kth(x, x->sz);
  t = merge(x, y);
  return res;
}

Node *get_next(Node *&t, int v) {
  auto [x, y] = split(t, v + 1);
  Node *res = kth(y, 1);
  t = merge(x, y);
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &[q, c] : a) cin >> c >> q, q = -q;
  sort(a.begin(), a.end());
  int q;
  cin >> q;
  vector<Node *> nodes(q);
  Node *t = nullptr;
  for (auto &node : nodes) {
    int x;
    cin >> x;
    node = new Node(x);
    t = merge(t, node);
  }
  for (auto &[_, c] : a) {
    auto [x, y] = split(t, c);
    if (y != nullptr) y->apply(c, 1);
    t = merge(x, y);
  }
  function<void(Node *)> dfs = [&](Node *node) {
    if (node == nullptr) return;
    node->push();
    dfs(node->l), dfs(node->r);
  };
  dfs(t);
  for (auto &node : nodes) {
    cout << node->a << " ";
    delete node;
  }
  cout << "\n";
}
