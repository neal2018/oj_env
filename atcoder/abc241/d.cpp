#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct Node {
  Node *l, *r;
  ll s, sz;
  // int t = 0, a = 0, g = 0; // for lazy propagation
  ll w;

  Node(ll _s) : l(nullptr), r(nullptr), s(_s), sz(1), w(rng()) {}
  void apply() {
    // for lazy propagation
    // s -= vt;
    // t += vt, a += vg, g += vg;
  }
  void push() {
    // for lazy propagation
    // if (l != nullptr) l->apply(t, g);
    // if (r != nullptr) r->apply(t, g);
    // t = g = 0;
  }
  void pull() { sz = 1 + (l ? l->sz : 0) + (r ? r->sz : 0); }
};

std::pair<Node *, Node *> split(Node *t, ll v) {
  // < v, >= v
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

Node *insert(Node *t, ll v) {
  auto [x, y] = split(t, v);
  return merge(merge(x, new Node(v)), y);
}

Node *erase(Node *t, ll v) {
  auto [x, y] = split(t, v);
  auto [p, q] = split(y, v + 1);
  return merge(merge(x, merge(p->l, p->r)), q);
}

ll get_rank(Node *&t, ll v) {
  auto [x, y] = split(t, v);
  ll res = (x ? x->sz : 0) + 1;
  t = merge(x, y);
  return res;
}

Node *kth(Node *t, ll k) {
  // kth smallest, 1-base
  k--;
  while (true) {
    ll left_sz = t->l ? t->l->sz : 0;
    if (k < left_sz) {
      t = t->l;
    } else if (k == left_sz) {
      return t;
    } else {
      k -= left_sz + 1, t = t->r;
    }
  }
}

Node *get_prev(Node *&t, ll v) {
  auto [x, y] = split(t, v);
  Node *res = kth(x, x->sz);
  t = merge(x, y);
  return res;
}

Node *get_next(Node *&t, ll v) {
  auto [x, y] = split(t, v + 1);
  Node *res = kth(y, 1);
  t = merge(x, y);
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  Node *t = nullptr;
  for (ll i = 0, x, k, op; i < n; i++) {
    cin >> op;
    if (op == 1) {
      cin >> x;
      t = insert(t, x);
    } else if (op == 2) {
      cin >> x >> k;
      auto [p, q] = split(t, x + 1);
      if (p != nullptr && p->sz >= k) {
        cout << kth(p, p->sz - k + 1)->s << "\n";
      } else {
        cout << -1 << "\n";
      }
      t = merge(p, q);
    } else {
      cin >> x >> k;
      auto [p, q] = split(t, x);
      if (q != nullptr && q->sz >= k) {
        cout << kth(q, k)->s << "\n";
      } else {
        cout << -1 << "\n";
      }
      t = merge(p, q);
    }
  }
}
