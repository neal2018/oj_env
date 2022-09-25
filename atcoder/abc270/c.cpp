#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, a, b;
  cin >> n >> a >> b, a--, b--;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<int> to_a, to_b;
  vector<int> stk;
  function<void(int, int)> dfs = [&](int node, int fa) {
    stk.push_back(node);
    if (node == a) to_a = stk;
    if (node == b) to_b = stk;
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      dfs(ne, node);
    }
    stk.pop_back();
  };
  dfs(0, -1);
  int pre = -1;
  reverse(to_a.begin(), to_a.end());
  reverse(to_b.begin(), to_b.end());
  while (to_a.size() && to_b.size() && to_a.back() == to_b.back()) {
    pre = to_a.back();
    to_a.pop_back(), to_b.pop_back();
  }
  to_a.push_back(pre);
  reverse(to_b.begin(), to_b.end());
  for (auto& x : to_b) to_a.push_back(x);
  for (auto& x : to_a) cout << x + 1 << " ";
  cout << "\n";
}
