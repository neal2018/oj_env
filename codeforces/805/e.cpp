#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    int f = 1;
    vector<int> freq(n);
    for (int i = 0, u, v; i < n; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
      if (u == v) f = 0;
      freq[u]++, freq[v]++;
    }
    if (ranges::max(freq) > 2 || f == 0) {
      cout << "NO\n";
      continue;
    }
    vector<int> seen(n, -1);
    for (int i = 0; i < n && f; i++) {
      if (seen[i] != -1) continue;
      int cur = i, pre = -1, len = 0;
      while (seen[cur] == -1) {
        seen[cur] = i;
        if (g[cur].empty()) break;
        if (g[cur][0] != pre) {
          pre = cur, cur = g[cur][0];
        } else {
          if (g[cur].size() == 1) break;
          pre = cur, cur = g[cur][1];
        }
        len++;
      }
      if (cur == i && (len & 1)) {
        f = 0;
      }
    }
    cout << (f ? "YES\n" : "NO\n");
  }
}
