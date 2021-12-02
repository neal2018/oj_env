#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094

#define ll long long


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector g(2, vector<vector<pair<int, int>>>(n));
  vector<int> u(m), v(m), w(m), pre(m, -1);
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i] >> w[i];
    u[i]--, v[i]--, w[i]--;
    g[w[i]][u[i]].push_back({v[i], i}), g[w[i]][v[i]].push_back({u[i], i});
  }
  vector<vector<pair<int, int>>> new_g(n);  // to, #
  for (auto& gg : g) {
    int start = 0, end = 0, end_edge = 0;
    function<void(int, int)> dfs = [&](int node, int from_edge) {
      end = node, end_edge = from_edge;
      if (!gg[node].size()) return;
      auto [ne, last] = gg[node].back();
      gg[node].pop_back();
      pre[last] = from_edge;
      dfs(ne, last);
    };
    for (int i = 0; i < n; i++) {
      while (gg[i].size() & 1) {
        start = i, dfs(i, -1);
        if (start == end) continue;
        new_g[start].push_back({end, end_edge});
        new_g[end].push_back({start, end_edge});
      }
    }
    for (int i = 0; i < n; i++)
      while (gg[i].size()) dfs(i, -1);
  }
  int start = 0, end = 0, end_edge = 0;
  function<void(int, int)> dfs = [&](int node, int from_edge) {
    end = node, end_edge = from_edge;
    if (!new_g[node].size()) return;
    auto [ne, last] = new_g[node].back();
    new_g[node].pop_back();
    pre[last] = from_edge;
    dfs(ne, last);
  };
  for (int i = 0; i < n; i++) {
    while (new_g[i].size() & 1) {
      start = i, dfs(i, -1);
      if (start == end) continue;
    }
  }
  for (int i = 0; i < n; i++)
    while (new_g[i].size()) dfs(i, -1);
}