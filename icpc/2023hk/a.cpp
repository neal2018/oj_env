#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0, p; i < n; i++) {
      cin >> p, p--;
      if (p != -1) g[p].push_back(i);
    }
    function<int(int)> dfs = [&](int node) {
      vector<int> child;
      for (auto& ne : g[node]) {
        child.push_back(dfs(ne));
      }
      sort(child.begin(), child.end());
      int cnt = int(child.size());
      int need = 1;
      for (int i = 0; i < cnt; i++) {
        need = max(need, child[i] + 1 - (i == (cnt - 1)));
      }
      return need;
    };
    int res = dfs(0);
    cout << res << "\n";
  }
}
