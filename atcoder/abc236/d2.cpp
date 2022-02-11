#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  n *= 2;
  vector<vector<ll>> a(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cin >> a[i][j], a[j][i] = a[i][j];
    }
  }
  ll res = 0;
  function<void(ll, ll)> dfs = [&](ll mask, ll cur) {
    if (mask == 0) {
      res = max(res, cur);
      return;
    }
    ll i = __builtin_ctzll(mask);
    for (int j = i + 1; j < n; j++) {
      if (mask >> j & 1) dfs(mask & (~(1 << i)) & (~(1 << j)), cur ^ a[i][j]);
    }
  };
  dfs((1 << n) - 1, 0);
  cout << res << "\n";
}
