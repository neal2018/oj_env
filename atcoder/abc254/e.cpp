#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  int qq;
  cin >> qq;
  while (qq--) {
    int x, k, res = 0;
    cin >> x >> k, x--;
    map<int, int> dis{{x, 0}};
    vector<int> q{x}, nq;
    for (; q.size(); swap(q, nq), nq.clear()) {
      for (auto& node : q) {
        res += node + 1;
        if (dis[node] == k) continue;
        for (auto& ne : g[node]) {
          if (dis.count(ne) == 0) {
            dis[ne] = dis[node] + 1;
            nq.push_back(ne);
          }
        }
      }
    }
    cout << res << "\n";
  }
}
