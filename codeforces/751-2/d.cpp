#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int inf = 1e9;
struct SegTree {
  int n;
  vector<int> t, index;
  SegTree(int n) : n(n) {
    t.resize(2 * n);
    index.resize(2 * n);
    for (int i = n; i < 2 * n; i++) {
      index[i] = i - n;  // 0 to n
      t[i] = inf;
    }
    for (int i = 0; i < n; i++) {
      index[i] = 1;
      t[i] = inf;
    }
  }
  void modify(int p, int value) {
    p += n;
    t[p] = min(t[p], value);
    for (p >>= 1; p > 0; p >>= 1) {
      t[p] = min(t[p * 2], t[p * 2 + 1]);
      if (t[p] == t[p * 2]) {
        index[p] = index[p * 2];
      } else {
        index[p] = index[p * 2 + 1];
      }
    }
  }
  pair<int, int> query(int l, int r) {
    int res = inf;
    int i = l;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) {
        res = min(res, t[l]);
        if (res == t[l]) {
          i = index[l];
        }
        l++;
      }
      if (r & 1) {
        res = min(t[--r], res);
        if (res == t[r]) {
          i = index[r];
        }
      }
    }
    return {res, i};
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1), to(n + 1, -1);
  vector<int> dp(n + 1, inf);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  map<int, vector<int>> rev;
  for (int i = 1; i <= n; i++) {
    rev[i + b[i]].push_back(i);
  }
  SegTree seg(n + 1);
  for (int _ = 0; _ < 10; _++) {
    for (int i = 1; i <= n; i++) {
      if (i <= a[i]) {
        dp[i] = 1;
        for (auto& x : rev[i]) seg.modify(x, dp[i]);
      } else {
        auto [mini, index] = seg.query(i - a[i], i);
        if (mini + 1 < dp[i]) {
          dp[i] = mini + 1, to[i] = index;
          for (auto& x : rev[i]) seg.modify(x, dp[i]);
        }
      }
    }
  }
  if (dp[n] == inf) {
    cout << -1 << '\n';
  } else {
    vector<ll> res;
    ll t = n;
    while (to[t] != -1) {
      res.push_back(to[t]);
      t = to[t] + b[to[t]];
    }
    cout << res.size() + 1 << '\n';
    for (auto& x : res) cout << x << " ";
    cout << "0\n";
  }
}