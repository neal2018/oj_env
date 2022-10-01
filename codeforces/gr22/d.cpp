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
    vector<int> b(n);
    for (auto& x : b) cin >> x;
    vector g(n + 2, vector<int>());
    int left = 0;
    int root = 0;
    for (int i = 1; i <= n; i++) {
      if (b[i - 1] >= i) left = max(left, i);
      g[b[i - 1]].push_back(i);
      if (b[i - 1] == n + 1) root = n + 1;
    }
    vector<int> deep(n + 2);
    function<int(int)> get_dep = [&](int node) {
      for (auto& ne : g[node]) {
        deep[node] = max(deep[node], get_dep(ne) + 1);
      }
      return deep[node];
    };
    get_dep(root);
    vector<int> a;
    function<void(int)> dfs = [&](int node) {
      if (node != 0 && node != n + 1) {
        a.push_back(node);
      }
      if (g[node].size() == 0) {
        return;
      }
      int heavy = g[node][0];
      for (auto& ne : g[node]) {
        if (deep[heavy] < deep[ne]) {
          heavy = ne;
        }
      }
      for (auto& ne : g[node]) {
        if (ne == heavy) continue;
        dfs(ne);
      }
      dfs(heavy);
    };
    dfs(root);
    cout << left << "\n";
    for (auto& x : a) cout << x << " ";
    cout << "\n";
  }
}
