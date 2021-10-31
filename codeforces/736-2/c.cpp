#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, m, u, v, q, type;
  cin >> n >> m;
  vector<vector<int> > g(n + 1);
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> type;
    if (type == 1) {
      cin >> u >> v;
      u--, v--;
    } else if (type == 2) {
      cin >> u >> v;
      u--, v--;
    } else {
    }
  }
  return 0;
}
