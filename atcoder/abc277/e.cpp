#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vector<array<int, 3>> edges(m);
  vector<vector<int>> g(2 * n);
  for (auto& [u, v, t] : edges) {
    cin >> u >> v >> t, u--, v--;
    int add = (1 - t) * n;
    g[u + add].push_back(v + add), g[v + add].push_back(u + add);
  }

  vector<int> a(k);
  for (auto& x : a) {
    cin >> x, x--;
    g[x].push_back(x + n), g[x + n].push_back(x);
  }

  vector<int> seen(2 * n);
  set<pair<int, int>> st{{0, 0}};
  while (st.size()) {
    auto [dis, node] = *st.begin();
    if (node == n - 1 || node == 2 * n - 1) {
      cout << dis << "\n";
      return 0;
    }
    st.erase(st.begin());
    if (seen[node]) continue;
    seen[node] = 1;
    for (auto& ne : g[node]) {
      int cost = dis + ((ne == node - n || ne == node + n) ? 0 : 1);
      if (seen[ne] == 0) {
        st.insert({cost, ne});
      }
    }
  }
  cout << "-1\n";
}
