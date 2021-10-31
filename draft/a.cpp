#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
constexpr int MOD = 1e9 + 7;
ll power(ll a, ll b, int res = 1) {
  for (; b; b >>= 1, a = a * a % MOD)
    if (b & 1) res = res * a % MOD;
  return res;
}
struct Node {
  int lc, rc, p;
};
struct SegTree {
  vector<Node> t = {{}};
  SegTree(int n) { t.reserve(n * 400); }
  int modify(int p, int l, int r, int x, int v) {
    t.push_back(t[p]);
    int u = t.size() - 1;
    if (r - l == 1) {
      t[u].p = 1ll * t[p].p * v % MOD;
    } else {
      int m = (l + r) / 2;
      (x < m) ? (t[u].lc = modify(t[p].lc, l, m, x, v)) : (t[u].rc = modify(t[p].rc, m, r, x, v));
      t[u].p = 1ll * t[t[u].lc].p * t[t[u].rc].p % MOD;
    }
    return u;
  }
  int query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return t[p].p;
    int m = (l + r) / 2, res = 1;
    if (x < m) res = 1ll * res * query(t[p].lc, l, m, x, y) % MOD;
    if (y > m) res = 1ll * res * query(t[p].rc, m, r, x, y) % MOD;
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, qq, l, r, last = 0;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  cin >> qq;
  int maxi = *max_element(a.begin(), a.end());
  vector<int> min_p(maxi + 1), inv(maxi + 1), primes;
  for (int i = 2; i <= maxi; ++i) {
    if (!min_p[i]) primes.push_back(min_p[i] = i);
    for (auto p : primes)
      if (i * p > maxi || i % (min_p[i * p] = p) == 0) break;
  }
  vector<vector<pair<int, int>>> stk(maxi + 1, {{-1, 0}});
  for (int i = 1; i <= maxi; ++i) inv[i] = power(i, MOD - 2);
  vector<int> rt(n + 1);
  SegTree seg(n + 1);
  seg.t[0].p = 1;
  for (int i = 0; i < n; ++i) {
    rt[i + 1] = rt[i];
    int x = a[i];
    while (x > 1) {
      int p = min_p[x], q = 1;
      while (min_p[x] == p) x /= p, q *= p;
      while (stk[p].size() > 1 && q > stk[p].back().second) {
        auto [pos, u] = stk[p].back();
        stk[p].pop_back();
        rt[i + 1] = seg.modify(rt[i + 1], 0, n + 1, pos + 1, u);
        rt[i + 1] = seg.modify(rt[i + 1], 0, n + 1, stk[p].back().first + 1, inv[u]);
      }
      rt[i + 1] = seg.modify(rt[i + 1], 0, n + 1, stk[p].back().first + 1, q);
      stk[p].emplace_back(i, q);
    }
    rt[i + 1] = seg.modify(rt[i + 1], 0, n + 1, i + 1, inv[a[i]]);
  }
  while (qq--) {
    cin >> l >> r;
    l = (l + last) % n, r = (r + last) % n;
    if (l > r) swap(l, r);
    cout << (last = seg.query(rt[r + 1], 0, n + 1, 0, l + 1)) << "\n";
  }
  return 0;
}