#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<array<int, 2>>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back({v, i}), g[v].push_back({u, i});
  }
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  map<int, int> mp;
  for (auto& x : a) mp[x]++;
  for (auto it = mp.rbegin(); it != mp.rend(); it++) {
    if (it->second > 2) {
      for (int i = 0; i < n - 1; i++) cout << it->first << "\n";
      return 0;
    } else if (it->second == 2) {
      vector<int> res(n - 1, -1);
      vector<int> endpoints;
      for (int i = 0; i < n; i++) {
        if (a[i] == it->first) endpoints.push_back(i);
      }
      vector<array<int, 2>> path;  // node, edge
      vector<array<int, 2>> cur_path;
      function<void(int, int)> dfs = [&](int node, int fa) {
        if (node == endpoints[1]) {
          path = cur_path;
          return;
        }
        for (auto& [ne, id] : g[node]) {
          if (ne == fa) continue;
          cur_path.push_back({node, id});
          dfs(ne, node);
          cur_path.pop_back();
        }
      };
      dfs(endpoints[0], -1);
      path.push_back({endpoints[1], -1});

      map<int, int> freq;
      int maxi = 0;
      vector<int> seen(n);
      function<void(int, int)> collect = [&](int node, int fa) {
        seen[node] = 1;
        freq[a[node]]++;
        if (freq[a[node]] >= 2) maxi = max(maxi, a[node]);
        for (auto& [ne, id] : g[node]) {
          if (ne == fa || seen[ne]) continue;
          collect(ne, node);
        }
      };
      for (auto path_it = path.begin(); path_it != path.end(); path_it++) {
        auto& [node, edge] = *path_it;
        if (node == endpoints[1]) break;
        collect(node, (*next(path_it))[0]);
        res[edge] = max(res[edge], maxi);
      }
      freq.clear(), maxi = 0, seen = vector<int>(n);
      for (auto path_it = path.rbegin(); path_it != path.rend(); path_it++) {
        auto& [node, edge] = *path_it;
        if (edge != -1) res[edge] = max(res[edge], maxi);
        collect(node, node == endpoints[0] ? -1 : (*next(path_it))[0]);
      }

      for (auto& x : res) cout << (x == -1 ? it->first : x) << "\n";
      return 0;
    }
  }
  for (int i = 0; i < n - 1; i++) cout << 0 << "\n";
}
