#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < m; i++) {
      cin >> u >> v, u--, v--;
      g[v].push_back(u);
    }
    vector<int> dist(n, inf);
    vector<int> q{0}, nq, order{0};
    dist[0] = 1;
    for (; q.size(); swap(q, nq), nq.clear()) {
      for (auto& node : q) {
        for (auto& ne : g[node]) {
          if (dist[ne] == inf) {
            dist[ne] = dist[node] + 1;
            nq.push_back(ne);
            order.push_back(ne);
          }
        }
      }
    }
    if (*max_element(dist.begin(), dist.end()) == inf) {
      cout << "INFINITE\n";
      continue;
    }
    cout << "FINITE\n";
    cout << accumulate(dist.begin(), dist.end(), 0) << "\n";
    vector<vector<int>> res(n);
    for (auto& node : order) {
      for (int i = 0; i < dist[node]; i++) {
        res[i].push_back(node);
      }
    }
    for (auto& v : res) {
      reverse(v.begin(), v.end());
      for (auto& x : v) cout << x + 1 << " ";
    }
    cout << "\n";
  }
}
