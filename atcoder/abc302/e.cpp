#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<set<int>> g(n);
  int res = n;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, v;
      cin >> u >> v, u--, v--;
      if (g[u].size() == 0) res--;
      if (g[v].size() == 0) res--;
      g[u].insert(v), g[v].insert(u);
      cout << res << "\n";
    } else {
      int v;
      cin >> v, v--;
      if (g[v].size() != 0) res++;
      for (auto it = g[v].begin(); it != g[v].end();) {
        auto ne = *it;
        g[ne].erase(v);
        if (g[ne].size() == 0) res++;
        it = g[v].erase(it);
      }
      cout << res << "\n";
    }
  }
}
