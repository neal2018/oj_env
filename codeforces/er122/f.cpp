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
  SegTree(ll _n) : n(_n), h((ll)log2(n)), t(n * 2) {}
  void apply(ll x, ll v) {
    if (v == 0) return;
    t[x].sum = t[x].total - t[x].sum;
    t[x].cnt = t[x].cnt_total - t[x].cnt;
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
  int n;
  cin >> n;
  vector<vector<array<int, 2>>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back({v, i + 1}), g[v].push_back({u, i + 1});
  }
  int root = 0, cur = 0;
  vector<int> parent(n), deep(n), hson(n), top(n), sz(n), fa_e(n), dfn(n, -1);
  function<int(int, int, int)> dfs = [&](int node, int fa, int dep) {
    deep[node] = dep, sz[node] = 1, parent[node] = fa;
    for (auto &[ne, i] : g[node]) {
      if (ne == fa) {
        fa_e[node] = i;
        continue;
      }
      sz[node] += dfs(ne, node, dep + 1);
      if (!hson[node] || sz[ne] > sz[hson[node]]) hson[node] = ne;
    }
    return sz[node];
  };
  function<void(int, int)> dfs2 = [&](int node, int t) {
    top[node] = t, dfn[node] = cur++;
    if (!hson[node]) return;
    dfs2(hson[node], t);
    for (auto &[ne, i] : g[node]) {
      if (ne == parent[node] || ne == hson[node]) continue;
      dfs2(ne, ne);
    }
  };
  dfs(root, -1, 0), dfs2(root, root);
  SegTree seg(n);
  seg.t[n] = {0, 0, 1, 1};
  for (int i = 1; i < n; i++) seg.t[dfn[i] + n] = {0, fa_e[i], 0, 1};
  for (int i = n - 1; i > 0; i--) seg.t[i] = pull(seg.t[i * 2], seg.t[i * 2 + 1]);
  ll x, op, cnt = 1;
  while (true) {
    cin >> op;
    if (op == 3 || op == 0) {
      return 0;
    }
    if (op == 1) {
      cin >> x, x--;
      while (x != -1) {
        seg.modify(dfn[top[x]], dfn[x] + 1, 1);
        x = parent[top[x]];
      }
      cnt++;
      if (cnt & 1) {
        cout << 0 << endl;
      } else {
        auto node = seg.query(0, n);
        if (node.cnt != cnt / 2) {
          cout << 0 << endl;
        } else {
          cout << node.sum << endl;
        }
      }
    } else {
      if ((cnt & 1) || seg.query(0, n).cnt != cnt / 2) {
        cout << 0 << endl;
      } else {
        vector<ll> good;
        for (int i = 0; i < n; i++) {
          auto node = seg.query(i, i + 1);
          if (node.cnt == 1) {
            good.push_back(node.sum);
          }
        }
        sort(good.begin(), good.end());
        cout << good.size();
        for (auto &xx : good) cout << " " << xx;
        cout << endl;
      }
    }
  }
}
