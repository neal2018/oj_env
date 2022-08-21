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
  vector<map<int, int>> trie(1);
  vector<int> cnt(1);
  ll res = 0;
  function<void(int, int, int)> dfs = [&](int node, int fa, int cur) {
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      int deg = int(g[ne].size());
      if (trie[cur].count(deg) == 0) {
        trie.emplace_back();
        cnt.push_back(0);
        trie[cur][deg] = int(trie.size()) - 1;
      }
      int nex = trie[cur][deg];
      if (cnt[nex] == 0) {
        cnt[nex]++, res++;
      }
      dfs(ne, node, nex);
    }
  };
  dfs(0, -1, 0);
  cout << res + 1 << "\n";
}
