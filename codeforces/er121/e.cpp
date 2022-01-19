#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094
constexpr ll MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n), can(n), cnt(n);  // sub tree
  for (auto& x : a) cin >> x;
  vector<vector<int>> g(n);
  for (int i = 0, x, y; i < n - 1; i++) {
    cin >> x >> y, x--, y--;
    g[x].push_back(y), g[y].push_back(x);
  }

  function<void(int, int)> dfs = [&](int node, int fa) {
    if (a[node]) can[node] = 1;
    cnt[node] = a[node];
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      dfs(ne, node);
      cnt[node] += cnt[ne];
      if (a[ne] || (can[ne] && cnt[ne] >= 2)) can[node] = 1;
    }
  };
  dfs(0, -1);
  function<void(int, int, int)> dfs2 = [&](int node, int fa, int count) {
    if (!can[node] && fa != -1) {
      if (a[fa] || (count >= 2 && can[fa])) can[node] = 1;
    }
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      dfs2(ne, node, count + cnt[node] - cnt[ne]);
    }
  };
  dfs2(0, -1, 0);
  for (auto& x : can) cout << x << " ";
  cout << "\n";
}
