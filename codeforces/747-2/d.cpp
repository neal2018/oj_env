#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, m, u, v;
  string s;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    vector<int> p(2 * n);
    iota(p.begin(), p.end(), 0);
    function<int(int)> find = [&](int x) { return p[x] == x ? x : (p[x] = find(p[x])); };
    auto merge = [&](int x, int y) { p[find(x)] = find(y); };
    int contradiction = 0;
    for (int i = 0; i < m; i++) {
      cin >> u >> v >> s;
      u--, v--;
      if (s[0] == 'i') {
        if (find(u) == find(v)) {
          contradiction = 1;
        } else {
          merge(u + n, v);
          merge(u, v + n);
        }
      } else {
        if (find(u + n) == find(v)) {
          contradiction = 1;
        } else {
          merge(u, v);
          merge(u + n, v + n);
        }
      }
    }
    if (contradiction) {
      cout << -1 << '\n';
    } else {
      unordered_map<int, int> mp, seen;
      for (int i = 0; i < n; i++) mp[find(i)]++;
      int res = 0;
      for (int i = 0; i < n; i++) {
        if (seen[find(i)]) continue;
        res += max(mp[find(i)], mp[find(i + n)]);
        seen[find(i)] = 1, seen[find((i + n))] = 1;
      }
      cout << res << '\n';
    }
  }
}