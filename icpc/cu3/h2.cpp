#include <bits/stdc++.h>
using namespace std;
#define ll long long
mt19937 rnd((unsigned)std::chrono::steady_clock::now().time_since_epoch().count());

struct Node {
  Node *l, *r;
  int s, sz;
  int lazy = 0;
  ll w;

  Node(int _s) : l(nullptr), r(nullptr), s(_s), sz(1), w(rnd()) {}
  void apply() {
    // for lazy propagation
    lazy ^= 1;
  }
  void push() {
    // for lazy propagation
    if (lazy) {
      swap(l, r);
      if (l != nullptr) l->apply();
      if (r != nullptr) r->apply();
      lazy = 0;
    }
  }
  void pull() { sz = 1 + (l ? l->sz : 0) + (r ? r->sz : 0); }
};

std::pair<Node *, Node *> split(Node *t, int v) {
  if (t == nullptr) return {nullptr, nullptr};
  t->push();
  int left_sz = t->l ? t->l->sz : 0;
  if (left_sz < v) {
    auto [x, y] = split(t->r, v - left_sz - 1);
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
  if (p->w < q->w) {
    p->push();
    p->r = merge(p->r, q);
    p->pull();
    return p;
  } else {
    q->push();
    q->l = merge(p, q->l);
    q->pull();
    return q;
  }
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
  string s;
  getline(cin, s);
  int n = int(s.size());
  int m;
  cin >> m;
  Node *t = nullptr;
  for (int i = 0; i < n; i++) {
    t = merge(t, new Node(i));
  }
  // string ss = s;
  for (int tt; m--;) {
    cin >> tt;
    {
      int l = 1, r = tt;
      if (l <= r) {
        auto [x, y] = split(t, r);
        auto [p, q] = split(x, l - 1);
        q->lazy ^= 1;
        t = merge(merge(p, q), y);
      }
    }
    {
      int l = tt + 1, r = n;
      if (l <= r) {
        auto [x, y] = split(t, r);
        auto [p, q] = split(x, l - 1);
        q->lazy ^= 1;
        t = merge(merge(p, q), y);
      }
    }
    ///
    // string pre = ss.substr(0, tt), remain = ss.substr(tt);
    // reverse(pre.begin(), pre.end());
    // reverse(remain.begin(), remain.end());
    // ss = pre + remain;
    // string ttt = "";
    // function<void(Node *)> dfs = [&](Node *node) {
    //   if (!node) return;
    //   if (node->lazy) node->push();
    //   dfs(node->l);
    //   ttt += s[node->s];
    //   dfs(node->r);
    // };
    // dfs(t);
    // cout << "tt="<< ttt << "\n";
    // cout << "ss="<< ss << "\n";
  }
  string tt = "";
  function<void(Node *)> dfs = [&](Node *node) {
    if (!node) return;
    if (node->lazy) node->push();
    dfs(node->l);
    tt += s[node->s];
    dfs(node->r);
  };
  dfs(t);
  cout << tt << "\n";
  // cout << ss << "\n";
  // assert(tt == ss);
  // cout << "\n";
}