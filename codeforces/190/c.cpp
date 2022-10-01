#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<char> res(n);
  vector<int> seen(n), sz(n);
  function<int(int, int)> get_size = [&](int node, int fa) {
    sz[node] = 1;
    for (auto& ne : g[node]) {
      if (ne == fa || seen[ne]) continue;
      sz[node] += get_size(ne, node);
    }
    return sz[node];
  };
  function<int(int, int, int)> find_centroid = [&](int node, int fa, int t) {
    for (auto& ne : g[node]) {
      if (ne != fa && !seen[ne] && sz[ne] > t / 2) return find_centroid(ne, node, t);
    }
    return node;
  };
  function<void(int, char)> solve = [&](int node, char cur) {
    get_size(node, -1);
    auto c = find_centroid(node, -1, sz[node]);
    seen[c] = 1;
    res[c] = cur;
    for (auto& ne : g[c]) {
      if (seen[ne]) continue;
      solve(ne, char(cur + 1)); // we can pass c here to build tree
    }
  };
  solve(0, 'A');
  for (auto& x : res) cout << x << " ";
}
