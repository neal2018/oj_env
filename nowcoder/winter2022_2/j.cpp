#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094
struct Node {
  int init = 0;
  int start, end;
  ll cnt[6][6] = {}, mini = 1e18;
};
// fire:0, blast:1, ice:2
constexpr array<int, 3> get_ele(int x) {
  if (x == 1) {
    return {0, 0, 0};
  } else if (x == 2) {
    return {0, 0, 1};
  } else if (x == 3) {
    return {0, 0, 2};
  } else if (x == 4) {
    return {2, 2, 2};
  } else if (x == 5) {
    return {0, 2, 2};
  } else if (x == 6) {
    return {1, 2, 2};
  } else if (x == 7) {
    return {1, 1, 1};
  } else if (x == 8) {
    return {0, 1, 1};
  } else if (x == 9) {
    return {1, 1, 2};
  } else {
    return {0, 1, 2};
  }
}
int save[11][11][11][11];
vector<int> sz(11);
vector<vector<array<int, 3>>> per(11);

int get_diff(int aa, int i, int bb, int j) {
  int res = 0;
  auto& a = per[aa][i];
  auto& b = per[bb][j];
  if (a[2] == b[0]) res = min(res, -1);
  if (a[1] == b[0] && a[2] == b[1]) res = min(res, -2);
  if (a == b) res = min(res, -3);
  return save[aa][i][bb][j] = res;
}
int get_sz(int x) {
  int cnt = 0;
  auto a = get_ele(x);
  do {
    cnt++;
    per[x].push_back(a);
  } while (next_permutation(a.begin(), a.end()));
  return cnt;
}
Node new_node(int v) {
  Node vv;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      vv.cnt[i][j] = 1e18;
    }
  }
  for (int i = 0; i < 6; i++) {
    vv.cnt[i][i] = 3;
  }
  vv.start = v, vv.end = v, vv.init = 1, vv.mini = 3;
  return vv;
}
struct SegTree {
  int n;
  vector<Node> t;
  SegTree(int _n) : n(_n) { t.resize(2 * n); }
  Node merge(const Node& a, const Node& b) {
    Node c;
    if (!a.init) return c = b, c;
    if (!b.init) return c = a, c;
    c.init = 1;
    c.start = a.start;
    c.end = b.end;
    // int need = 0;
    if (a.end == b.start) {
      for (int ss = 0; ss < sz[c.start]; ss++) {
        for (int ee = 0; ee < sz[c.end]; ee++) {
          c.cnt[ss][ee] = 1e18;
          for (int i = 0; i < sz[a.end]; i++) {
            c.cnt[ss][ee] = min(c.cnt[ss][ee], a.cnt[ss][i] + b.cnt[i][ee] - 3);
            c.mini = min(c.mini, c.cnt[ss][ee]);
          }
        }
      }
      return c;
    }
    for (int ss = 0; ss < sz[c.start]; ss++) {
      for (int ee = 0; ee < sz[c.end]; ee++) {
        c.cnt[ss][ee] = 1e18;
        for (int i = 0; i < sz[a.end]; i++) {
          for (int j = 0; j < sz[b.start]; j++) {
            int diff = save[a.end][i][b.start][j];
            c.cnt[ss][ee] = min(c.cnt[ss][ee], a.cnt[ss][i] + b.cnt[j][ee] + diff);
            c.mini = min(c.mini, c.cnt[ss][ee]);
          }
        }
      }
    }
    return c;
  }
  void modify(int p, int v) {
    Node vv = new_node(v);
    t[p += n] = vv;
    for (p /= 2; p; p /= 2) t[p] = merge(t[2 * p], t[2 * p + 1]);
  }
  Node query(int l, int r) {
    Node left, right;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) left = merge(left, t[l++]);
      if (r & 1) right = merge(t[--r], right);
    }
    return merge(left, right);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  for (int i = 1; i <= 10; i++) sz[i] = get_sz(i);
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      for (int ii = 0; ii < sz[i]; ii++) {
        for (int jj = 0; jj < sz[j]; jj++) get_diff(i, ii, j, jj);
      }
    }
  }
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  SegTree seg(n);
  for (int i = 0; i < n; i++) seg.t[i + n] = new_node(a[i]);
  for (int i = n - 1; i > 0; i--) {
    seg.t[i] = seg.merge(seg.t[2 * i], seg.t[2 * i + 1]);
  }
  while (q--) {
    int op, l, r;
    cin >> op >> l >> r;
    l--;
    if (op == 1) {
      Node node = seg.query(l, r);
      cout << node.mini << "\n";
    } else {
      seg.modify(l, r);
    }
  }
}