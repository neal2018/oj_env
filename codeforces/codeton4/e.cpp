#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), deg(n);
    for (auto& x : a) cin >> x;

    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < m; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
      deg[u]++, deg[v]++;
    }

    vector<int> checked(n);
    [&] {
      for (int i = 0; i < n; i++) {
        if (a[i] == 0 && checked[i] == 0) {
          set<int> seen{i};
          set<array<int, 2>> st{{a[i], i}};
          checked[i] = 1;
          int sz = 0;
          while (st.size() && (*st.begin())[0] <= sz) {
            auto [val, node] = *st.begin();
            st.erase(st.begin());
            sz++, seen.insert(node);
            for (auto& ne : g[node]) {
              if (seen.count(ne) == 0) {
                st.insert({a[ne], ne}), seen.insert(ne), checked[ne] = 1;
              }
            }
          }
          if (sz == n) {
            cout << "YES\n";
            return;
          }
        }
      }
      cout << "NO\n";
    }();
  }
}
