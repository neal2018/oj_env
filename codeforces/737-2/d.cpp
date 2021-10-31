#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const pii NIL{0, -1};

struct SegTree {
  int n, h = 0;
  vector<pii> t, lazy;
  SegTree(int n) : n(n), t(n * 2, NIL), lazy(n * 2, NIL), h(log2(n)) {}
  void apply(int x, pii v) {
    t[x] = max(t[x], v);
    lazy[x] = max(lazy[x], v);
  }
  void build(int l) {
    for (l = (l + n) / 2; l > 0; l >>= 1) {
      t[l] = max({t[2 * l], t[2 * l + 1], lazy[l]});
    }
  }
  void push(int l) {
    l += n;
    for (int s = h; s > 0; s--) {
      int i = l >> s;
      apply(2 * i, lazy[i]), apply(2 * i + 1, lazy[i]);
      lazy[i] = NIL;
    }
  }
  void modify(int l, int r, pii v) {
    push(l), push(r - 1);
    int l0 = l, r0 = r;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
    }
    build(l0), build(r0 - 1);
  }
  pii query(int l, int r) {
    push(l), push(r - 1);
    pii res = NIL;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = max(res, t[l++]);
      if (r & 1) res = max(t[--r], res);
    }
    return res;
  }
};

int main() {
  int n, m, a, b, c;
  cin >> n >> m;
  vector<vector<pii>> mp(n);
  vector<int> compress;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    mp[a - 1].push_back({b, c});
    compress.push_back(b);
    compress.push_back(c);
  }
  sort(compress.begin(), compress.end());
  compress.erase(unique(compress.begin(), compress.end()), compress.end());
  unordered_map<int, int> id;
  for (int i = 0; i < compress.size(); i++) {
    id[compress[i]] = i;
  }
  SegTree seg(id.size());
  vector<int> prev(n, -1);
  for (int i = 0; i < n; i++) {
    pii maxi = NIL;
    for (auto& [l, r] : mp[i]) {
      maxi = max(maxi, seg.query(id[l], id[r] + 1));
    }
    prev[i] = maxi.second;
    maxi.first++;
    maxi.second = i;
    for (auto& [l, r] : mp[i]) {
      seg.modify(id[l], id[r] + 1, maxi);
    }
  }
  pii res = seg.query(0, id.size());
  cout << n - res.first << endl;
  vector<int> save(n);
  int curr = res.second;
  while (curr != -1) {
    save[curr] = 1;
    curr = prev[curr];
  }
  for (int i = 0; i < n; i++) {
    if (save[i] == 0) {
      cout << i + 1 << " ";
    }
  }
}