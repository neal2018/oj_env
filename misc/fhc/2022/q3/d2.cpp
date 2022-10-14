/**
 *    author:  tourist
 *    created: 08.10.2022 21:14:41
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

class segtree {
public:
  struct node {
    int x = 0;

    void apply(int l, int r, int v) { x = v; }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.x = __gcd(a.x, b.x);
    return res;
  }

  inline void push(int x, int l, int r) {}

  inline void pull(int x, int z) { tree[x] = unite(tree[x + 1], tree[z]); }

  int n;
  vector<node> tree;

  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }

  template <typename M>
  void build(int x, int l, int r, const vector<M> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }

  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }

  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M &...v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }

  int find_first_knowingly(int x, int l, int r, const function<bool(const node &)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }

  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node &)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  int find_last_knowingly(int x, int l, int r, const function<bool(const node &)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }

  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node &)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  template <typename M>
  segtree(const vector<M> &v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }

  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }

  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }

  template <typename... M>
  void modify(int ll, int rr, const M &...v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }

  // find_first and find_last call all FALSE elements
  // to the left (right) of the sought position exactly once

  int find_first(int ll, int rr, const function<bool(const node &)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }

  int find_last(int ll, int rr, const function<bool(const node &)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> from(m), to(m);
    for (int i = 0; i < m; i++) {
      cin >> from[i] >> to[i];
      --from[i];
      --to[i];
    }
    vector<vector<int>> at(n);
    vector<int> who(n);
    vector<int> vid(n);
    for (int i = 0; i < n; i++) {
      at[i].push_back(i);
      who[i] = i;
      vid[i] = i;
    }
    vector<int> init(n);
    iota(init.begin(), init.end(), 1);
    init[n - 1] = 0;
    segtree st(init);
    int ans = -1;
    for (int it = 0; it < m; it++) {
      auto Remove = [&](int x) { st.modify(x, x, 0); };
      int a = from[it];
      int b = to[it];
      int &va = who[a];
      int &vb = who[b];
      if (va == -1) {
        continue;
      }
      if (vb == -1) {
        vb = va;
        va = -1;
        continue;
      }
      if (at[va].size() < at[vb].size()) {
        for (int x : at[va]) {
          assert(vid[x] == va);
          if (x > 0 && vid[x - 1] == vb) {
            Remove(x - 1);
          }
          if (x < n - 1 && vid[x + 1] == vb) {
            Remove(x);
          }
        }
        for (int x : at[va]) {
          vid[x] = vb;
          at[vb].push_back(x);
        }
        at[va].clear();
        va = -1;
      } else {
        for (int x : at[vb]) {
          assert(vid[x] == vb);
          if (x > 0 && vid[x - 1] == va) {
            Remove(x - 1);
          }
          if (x < n - 1 && vid[x + 1] == va) {
            Remove(x);
          }
        }
        for (int x : at[vb]) {
          vid[x] = va;
          at[va].push_back(x);
        }
        at[vb].clear();
        vb = va;
        va = -1;
      }
      int cur = st.get(0, n - 1).x;
      if (cur % k == 0) {
        ans = it + 1;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
