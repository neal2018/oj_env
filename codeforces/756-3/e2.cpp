#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, k;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    vector<int> q(k), nq, dis(n, 1e9), seen(n);
    vector<vector<int>> g(n);
    for (auto& x : q) cin >> x, x--;
    for (int i = 0, u, v; i < n - 1; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
    }
    for (auto& x : q) dis[x] = 0;
    for (; q.size(); swap(q, nq), nq.clear())
      for (auto& node : q)
        for (auto& ne : g[node])
          if (dis[ne] > dis[node] + 1) dis[ne] = dis[node] + 1, nq.push_back(ne);
    q = {0}, seen[0] = 1;
    int can = 0, res = 0;
    for (int step = 0; q.size(); swap(q, nq), nq.clear(), step++)
      for (auto& node : q) {
        if (node != 0 && g[node].size() == 1) can = 1;
        for (auto& ne : g[node]) {
          if (seen[ne]) continue;
          seen[ne] = 1;
          (step + 1 >= dis[ne]) ? res++ : (nq.push_back(ne), 0);
        }
      }
    cout << (can ? -1 : res) << '\n';
  }
}
