#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<vector<ll>> c(3, vector<ll>(n));
  for (auto& a : c) {
    for (auto& x : a) cin >> x;
  }
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  int root = 0;
  for (int i = 0; i < n; i++) {
    if (g[i].size() > 2) {
      cout << "-1\n";
      return 0;
    } else if (g[i].size() == 1) {
      root = i;
    }
  }
  vector dp(3, vector<ll>(3));
  vector<int> order(n, root);
  for (int i = 0, cur = root, pre = root; i < n; i++) {
    vector ndp(3, vector<ll>(3));
    for (int x = 0; x < 3; x++) {
      for (int y = 0; y < 3; y++) {
        if (x != y) {
          int z = 0 ^ 1 ^ 2 ^ x ^ y;
          ndp[y][z] = c[z][cur] + dp[x][y];
        }
      }
    }
    dp = ndp;
    if (i < n - 1) {
      int nex = (g[cur][0] == pre) ? g[cur][1] : g[cur][0];
      pre = cur, cur = nex;
      order[i + 1] = cur;
    }
  }
  ll mini = inf;
  int last_x = -1, last_y = -1;
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      if (x != y) {
        if (dp[x][y] < mini) last_x = x, last_y = y, mini = dp[x][y];
      }
    }
  }
  cout << mini << "\n";
  vector<int> color = {0 ^ 1 ^ 2 ^ last_x ^ last_y, last_x, last_y};
  vector<int> res(n);
  for (int i = 0; i < n; i++) res[order[i]] = color[(i + 3 - n % 3) % 3];
  for (auto& x : res) cout << x + 1 << " ";
  cout << "\n";
}
