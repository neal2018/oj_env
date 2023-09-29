#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<array<int, 2>> a(k);
  for (auto& [x, y] : a) cin >> x >> y, x--;
  sort(a.begin(), a.end(), [&](auto x, auto y) { return x[1] > y[1]; });
  vector<int> seen(n);
  int bad = n;
  for (auto& [x, y] : a) {
    if (y < seen[x]) continue;
    if (seen[x] == 0) bad--;
    seen[x] = y + 1;
    vector<int> q{x}, nq;
    for (; q.size(); swap(q, nq), nq.clear()) {
      for (auto& node : q) {
        if (seen[node] == 1) continue;
        for (auto& ne : g[node]) {
          if (seen[ne] >= seen[node] - 1) continue;
          if (seen[ne] == 0) bad--;
          seen[ne] = seen[node] - 1;
          nq.push_back(ne);
        }
      }
    }
    if (bad <= 0) break;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (seen[i]) cnt++;
  }
  cout << cnt << "\n";

  for (int i = 0; i < n; i++) {
    if (seen[i]) cout << i + 1 << " ";
  }
  cout << "\n";
}
