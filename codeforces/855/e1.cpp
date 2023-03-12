#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s, t;
    cin >> n >> k >> s >> t;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
      for (auto& j : {i + k, i + k + 1}) {
        if (j >= n) continue;
        g[i].push_back(j), g[j].push_back(i);
      }
    }
    vector<int> seen(n), freq(26);
    function<void(int)> dfs = [&](int node) {
      seen[node] = 1;
      freq[s[node] - 'a']++;
      freq[t[node] - 'a']--;
      for (auto& ne : g[node]) {
        if (seen[ne]) continue;
        dfs(ne);
      }
    };
    if ([&] {
          for (int i = 0; i < n; i++) {
            if (seen[i]) continue;
            freq = vector<int>(26);
            dfs(i);
            for (auto& x : freq) {
              if (x != 0) return false;
            }
          }
          return true;
        }()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
