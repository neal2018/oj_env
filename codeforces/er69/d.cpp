#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n), pre(n + 1);
  for (auto &x : a) cin >> x;
  for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
  vector<ll> st(m, inf);
  ll res = 0;
  for (int i = 0; i < n; i++) {
    st[i % m] = min(st[i % m], pre[i] - k * (i / m));
    for (int j = 0; j < m; j++) {
      auto val = st[j];
      ll cur = pre[i + 1] - val - k * (((i + 1) - j + m - 1) / m);
      res = max(res, cur);
    }
  }
  cout << res << "\n";
}
