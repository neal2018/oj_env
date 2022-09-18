#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n, qq;
    cin >> n >> qq;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
    }
    vector<int> sz, seen(n);
    vector<int> q{0}, nq;
    seen[0] = 1;
    for (; q.size(); swap(q, nq), nq.clear()) {
      sz.push_back(int(q.size()));
      for (auto& node : q) {
        for (auto& ne : g[node]) {
          if (seen[ne] == 0) {
            seen[ne] = 1, nq.push_back(ne);
          }
        }
      }
    }
    int id = 0, res = 0, acc = 0;
    while (qq--) {
      int x;
      cin >> x;
      acc++;;
      if (id < sz.size()) {
        if (sz[id] == acc) res += sz[id], id++, acc = 0;
      }
    }
    cout << res << "\n";
  }
}
