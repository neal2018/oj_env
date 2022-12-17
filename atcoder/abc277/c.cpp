#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  map<int, vector<int>> g;
  for (int i = 0, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  int res = 1;
  vector<int> q{1}, nq;
  unordered_set<int> seen;
  for (; q.size(); swap(q, nq), nq.clear()) {
    for (auto& node : q) {
      res = max(res, node);
      seen.insert(node);
      for (auto& ne : g[node]) {
        if (seen.count(ne) == 0) {
          nq.push_back(ne);
          seen.insert(ne);
        }
      }
    }
  }
  cout << res << "\n";
}
