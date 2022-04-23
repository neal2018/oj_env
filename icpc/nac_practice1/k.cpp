#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
int main() {
  ll n, root;
  cin >> n >> root;
  vector<vector<ll>> g(n);
  vector<ll> deg(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
    deg[u]++, deg[v]++;
  }
  int start = -1, end = -1;
  root = -1;
  for (int i = 0; i < n; i++) {
    if (deg[i] >= 3) {
      root = i;
    }
    if (deg[i] == 1) {
      if (start == -1) {
        start = i;
      } else {
        end = i;
      }
    }
  }
  if (root == -1) {
    cout << "1\n";
    cout << start << " " << end << "\n";
    return 0;
  }
  vector<ll> leaves;
  function<void(ll, ll)> dfs = [&](ll node, ll fa) {
    if (g[node].size() == 1) {
      leaves.push_back(node);
      return;
    } else {
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        dfs(ne, node);
      }
    }
  };
  dfs(root, -1);
  cout << (leaves.size() + 1) / 2 << "\n";
  ll offset = leaves.size() / 2;
  for (int i = 0; i < leaves.size() / 2; i++) {
    cout << leaves[i] << " " << leaves[i + offset] << "\n";
  }
  if (leaves.size() % 2 == 1) {
    cout << leaves.back() << " " << root << "\n";
  }
}