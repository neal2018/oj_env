#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
  Node *l, *r;
  int s, sz;
  ll w;

  Node(int _s) : l(nullptr), r(nullptr), s(_s), sz(1), w(rng()) {}
  void apply() {}
  void push() {}
  void pull() { sz = 1 + (l ? l->sz : 0) + (r ? r->sz : 0); }
};

std::pair<Node *, Node *> split(Node *t, int v) {
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

constexpr int SZ = 26, MAXN = 5e5 + 10;
int parent[MAXN], length[MAXN], e[MAXN][SZ], cnt[MAXN], a[MAXN];
Node *node[MAXN];

struct SAM {
  int last = 0, total = 1;
  void init() {
    memset(parent, 0, sizeof parent);
    memset(length, 0, sizeof length);
    memset(e, 0, sizeof e);
    memset(cnt, 0, sizeof cnt);
    parent[0] = -1;
  }
  int extend(int c, int t) {
    length[total] = length[last] + 1;
    int p = last, r = total++;
    last = r;
    node[r] = new Node(t);
    for (; p != -1 && e[p][c] == 0; p = parent[p]) e[p][c] = r;
    if (p != -1) {
      int q = e[p][c];
      if (length[q] == length[p] + 1) {
        parent[r] = q;
      } else {
        parent[total] = parent[q];
        length[total] = length[p] + 1;
        for (int i = 0; i < SZ; i++) e[total][i] = e[q][i];
        int qq = total++;
        parent[q] = parent[r] = qq;
        for (; p != -1 && e[p][c] == q; p = parent[p]) e[p][c] = qq;
      }
    }
    return r;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  int q;
  cin >> q;
  vector<pair<string, int>> qs(q);
  for (auto &[t, g] : qs) cin >> t >> g;
  SAM sam;
  sam.init();
  for (int i = 0; i < s.size(); i++) sam.extend(s[i] - 'a', i);
  for (int i = 1; i < sam.total; i++) cnt[length[i]]++;
  for (int i = 1; i < sam.total; i++) cnt[i] += cnt[i - 1];
  for (int i = 1; i < sam.total; i++) a[cnt[length[i]]--] = i;

  vector<int> res(q);
  vector<vector<int>> dispatch(sam.total);
  for (int i = 0; i < q; i++) {
    auto &[t, g] = qs[i];
    int curr = 0, f = 1;
    for (auto &cc : t) {
      int c = cc - 'a';
      if (e[curr][c] == 0) {
        f = 0;
        break;
      }
      curr = e[curr][c];
    }
    if (f) dispatch[curr].push_back(i);
  }

  for (int i = sam.total - 1; i > 0; i--) {
    int p = a[i];
    for (auto &qq : dispatch[p]) {
      auto &[t, g] = qs[qq];
      if (node[p] != nullptr && node[p]->sz >= g) {
        res[qq] = kth(node[p], g)->s - (int)t.size() + 2;
      }
    }
    node[parent[p]] = merge(node[parent[p]], node[p]);
  }
  for (auto &x : res) cout << (x ? x : -1) << "\n";
  return 0;
}