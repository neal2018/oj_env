#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int n, m;
string s;
struct spltr {
  struct node {
    int fa, sn[2], tag, siz;
  } ar[MAXN];
  int rt;
  void pushdown(int k) {
    if (!ar[k].tag) return;
    swap(ar[k].sn[0], ar[k].sn[1]);
    ar[ar[k].sn[0]].tag ^= 1, ar[ar[k].sn[1]].tag ^= 1;
    ar[k].tag = 0;
  }
  void pushup(int k) { ar[k].siz = ar[ar[k].sn[0]].siz + ar[ar[k].sn[1]].siz + 1; }
  int build(int l, int r) {
    if (l > r) return 0;
    int mid = (l + r) >> 1;
    ar[mid].sn[0] = build(l, mid - 1), ar[mid].sn[1] = build(mid + 1, r);
    ar[ar[mid].sn[0]].fa = ar[ar[mid].sn[1]].fa = mid;
    pushup(mid);
    return mid;
  }
  int gtnum(int x) {
    int p = rt;
    while (p) {
      pushdown(p);
      if (x <= ar[ar[p].sn[0]].siz)
        p = ar[p].sn[0];
      else if (x == ar[ar[p].sn[0]].siz + 1)
        return p;
      else
        x -= ar[ar[p].sn[0]].siz + 1, p = ar[p].sn[1];
    }
    return -1;
  }
  void rot(int k) {
    int p = ar[k].fa;
    int dir = ar[p].sn[1] == k, id = ar[ar[p].fa].sn[1] == p;
    ar[k].fa = ar[p].fa, ar[ar[p].fa].sn[id] = k;
    ar[ar[k].sn[dir ^ 1]].fa = p, ar[p].sn[dir] = ar[k].sn[dir ^ 1];
    ar[p].fa = k, ar[k].sn[dir ^ 1] = p;
    pushup(p), pushup(k);
  }
  void splay(int k, int gl) {
    gl = ar[gl].fa;
    while (ar[k].fa != gl) {
      int p = ar[k].fa;
      pushdown(p), pushdown(k);
      if (ar[p].fa == gl) {
        rot(k);
        return;
      }
      pushdown(ar[p].fa);
      int dir = ar[p].sn[1] == k, id = ar[ar[p].fa].sn[1] == p;
      if (dir == id)
        rot(p), rot(k);
      else
        rot(k), rot(k);
    }
  }
  void rev(int l, int r) {
    l = gtnum(l - 1), r = gtnum(r + 1);
    splay(l, rt), rt = l, splay(r, ar[rt].sn[1]);
    ar[ar[ar[rt].sn[1]].sn[0]].tag ^= 1;
  }
  void dfs(int k) {
    if (!k) return;
    pushdown(k);
    dfs(ar[k].sn[0]);
    if (k > 1 && k < n + 2) cout << s[k - 1 - 1];
    dfs(ar[k].sn[1]);
  }
} tr;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  n = s.length();
  cin >> m;
  tr.rt = tr.build(1, n + 2);
  cout << m << "\n";
  while (m--) {
    int x;
    cin >> x;
    // tr.rev(1, x);
    // tr.rev(x + 1, n);
  }
  tr.dfs(tr.rt);
  cout << "\n";
  return 0;
}