#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> deg(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x, x--;
      if (x != i) {
        deg[x]++;
        g[x].push_back(i);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    vector<int> seen(n);
    seen[i] = 1;
    function<int(int)> dfs = [&](int node) {
      int res = 0;
      for (auto& ne : g[node]) {
        if (!seen[ne]) {
          seen[ne] = 1;
          res += dfs(ne);
        }
      }
      return res + 1;
    };
    if (dfs(i) > k) {
      cout << 1 << "\n";
    } else {
      cout << 0 << "\n";
    }
  }
}