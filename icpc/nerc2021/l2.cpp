#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, m, s;
  cin >> n >> m >> s, s--;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v, u--, v--;
    if(v == s) continue;
    g[u].push_back(v);
  }
  vector<int> color(n, -1), parent(n, -1);
  function<void(int,int,int)> dfs = [&](int cur, int prev, int col) {
    if(color[cur] != col && color[cur] != -1) {
      cout << "Possible\n";
      vector<int> p1, p2 = {cur};
      int last = cur;
      while(last != -1) {
        p1.push_back(last);
        last = parent[last];
      }
      last = prev;
      while(last != -1) {
        p2.push_back(last);
        last = parent[last];
      }
      reverse(p1.begin(), p1.end());
      reverse(p2.begin(), p2.end());
      cout << (int)p1.size() << ' ';
      for(int v : p1) cout << v + 1 << ' ';
      cout << '\n';
      cout << (int)p2.size() << ' ';
      for(int v : p2) cout << v + 1 << ' ';
      cout << '\n';
      exit(0);
    }
    color[cur] = col;
    parent[cur] = prev;
    for(int v : g[cur]) {
      if(color[v] == col) continue;
      dfs(v, cur, col);
    }
  };
  for(int v : g[s]) dfs(v, s, v);
  cout << "Impossible\n";
}