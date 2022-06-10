#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct LinkCutTree {
  struct TreeNode {
    int p = 0, s[2] = {0, 0}, rev = 0, sz = 1, v_sz = 0;
  };
  vector<TreeNode> t;
  vector<int> stk;
  LinkCutTree(int n) : t(n + 1), stk(n + 1) { t[0].sz = 0; }
  void merge(int u, int x, int y) { t[u].sz = t[x].sz + t[y].sz + t[u].v_sz + 1; }
  void pull(int x) { merge(x, t[x].s[0], t[x].s[1]); }
  void rev(int x) { swap(t[x].s[0], t[x].s[1]), t[x].rev ^= 1; }
  void push(int x) {
    if (t[x].rev) rev(t[x].s[0]), rev(t[x].s[1]), t[x].rev = 0;
  }
  bool is_root(int u) { return t[t[u].p].s[0] != u and t[t[u].p].s[1] != u; }
  void rotate(int x) {
    int y = t[x].p, z = t[y].p, k = t[y].s[1] == x;
    if (!is_root(y)) t[z].s[t[z].s[1] == y] = x;
    t[x].p = z, t[y].s[k] = t[x].s[!k];
    t[t[x].s[!k]].p = y, t[x].s[!k] = y, t[y].p = x;
    pull(y), pull(x);
  }
  void splay(int x) {
    int sz = 0, a = x;
    for (stk[++sz] = a; !is_root(a);) stk[++sz] = a = t[a].p;
    while (sz) push(stk[sz--]);
    while (!is_root(x)) {
      int y = t[x].p, z = t[y].p;
      if (!is_root(y)) ((t[z].s[1] == y) != (t[y].s[1] == x)) ? rotate(x) : rotate(y);
      rotate(x);
    }
  }
  void access(int x) {
    for (int y = 0, z = x; z; y = z, z = t[z].p) {
      splay(z), t[z].v_sz += t[t[z].s[1]].sz - t[y].sz, t[z].s[1] = y, pull(z);
    }
    splay(x);
  }
  void make_root(int x) { access(x), rev(x); }
  int find_root(int x) {
    for (access(x); t[x].s[0]; x = t[x].s[0]) push(x);
    return splay(x), x;
  }
  void split(int x, int y) { make_root(y), access(x); }
  void link(int x, int y) {
    make_root(y), make_root(x);
    if (find_root(y) != x) t[x].p = y, t[y].v_sz += t[x].sz, pull(y), pull(x);
  }
  void cut(int x, int y) {
    make_root(x);
    if (find_root(y) == x && t[x].s[1] == y && !t[y].s[0]) {
      t[y].p = t[x].s[1] = 0, pull(x);
    }
  }
  void set(int x, function<void(void)> &&modify) { splay(x), modify(), pull(x); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  LinkCutTree lct(n);
  vector<vector<pair<int, int>>> edges(n);
  for (int i = 0, u, v, c; i < n - 1; i++) {
    // cin >> u >> v >> c, u--, v--, c--;
    cin >> u >> v >> c, c--;
    edges[c].push_back({u, v});
    lct.link(u, v);
  }

  ll res = 0;
  for (int c = 0; c < n; c++) {
    for (auto &[u, v] : edges[c]) lct.cut(u, v);
    for (auto &[u, v] : edges[c]) {
      lct.make_root(u), lct.make_root(v);
      res += ll(lct.t[u].sz) * lct.t[v].sz;
    }
    for (auto &[u, v] : edges[c]) lct.link(u, v);
  }
  cout << res << "\n";
}
