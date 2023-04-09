#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<int> deg(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
    deg[u]++, deg[v]++;
  }
  vector<int> q, nq;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 1) q.push_back(i);
  }
  for (;; swap(q, nq), nq.clear()) {
    for (auto& node : q) {
      for (auto& ne : g[node]) {
        if (--deg[ne] == 1) nq.push_back(ne);
      }
    }
    if (nq.size() == 0) break;
  }
  assert(q.size() == 1 || q.size() == 2);
  vector<int> dist(n);
  function<void(int, int, int)> dfs = [&](int node, int fa, int dep) {
    dist[node] = dep;
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      dfs(ne, node, dep + 1);
    }
  };
  if (q.size() == 1) {
    dfs(q[0], -1, 0);
  } else {
    dfs(q[0], q[1], 0);
    dfs(q[1], q[0], 0);
  }
  int maxi = *max_element(dist.begin(), dist.end()) + (q.size() == 2);
  vector<int> res(n + 1);
  for (int i = 0; i < n; i++) {
    res[maxi + dist[i]]++;
  }
  for (int i = n - 1; i >= 0; i--) {
    res[i] += res[i + 1];
  }
  for (int i = 1; i <= n; i++) cout << n - res[i] + (res[i] != 0) << " ";
  cout << "\n";
}
