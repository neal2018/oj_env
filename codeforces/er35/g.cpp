#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
  Node *l, *r;
  int s, sz;
  ll w;

  Node(int _s) : l(nullptr), r(nullptr), s(_s), sz(1), w(rng()) {}
  void push() {}
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
  vector<Node *> tree(101);
  for (int i = 0, x; i < n; i++) {
    cin >> x, tree[x] = merge(tree[x], new Node(i));
  }
  int qq;
  cin >> qq;
  while (qq--) {
    int l, r, x, y;
    cin >> l >> r >> x >> y, l--;
    auto [a, b] = split(tree[x], l);
    auto [p, q] = split(b, r);
    tree[x] = merge(a, q);
    tree[y] = merge(tree[y], p);
  }
  vector<int> res(n);
  function<void(Node *, int)> dfs = [&](Node *node, int id) {
    if (node == nullptr) return;
    res[node->s] = id;
    dfs(node->l, id), dfs(node->r, id);
  };
  for (auto i : views::iota(0, 101)) dfs(tree[i], i);
  for (auto &x : res) cout << x << " ";
  cout << "\n";
}
