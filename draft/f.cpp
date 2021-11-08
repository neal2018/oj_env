#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, n, m;
  string s;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    vector<int> to(n * m, -1), seen(n * m), dp(n * m, 1);
    // seen[i]: 0: untouched, 1: current, 2: finish
    for (int i = 0; i < n; i++) {
      cin >> s;
      for (int j = 0; j < m; j++) {
        if (s[j] == 'L' && j > 0) {
          to[i * m + j] = i * m + j - 1;
        } else if (s[j] == 'R' && j < m - 1) {
          to[i * m + j] = i * m + j + 1;
        } else if (s[j] == 'U' && i > 0) {
          to[i * m + j] = (i - 1) * m + j;
        } else if (s[j] == 'D' && i < n - 1) {
          to[i * m + j] = (i + 1) * m + j;
        }
      }
    }
    vector<pair<int, int>> q;
    int best = 0, remain = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        q = {{i * m + j, 1}};
        while (q.size()) {
          auto [node, rank] = q.back();
          q.pop_back();
          if (rank != -1) {
            if (to[node] == -1 || seen[node] == -1) {
              remain = 0;
              continue;
            }
            if (seen[to[node]] > 0) {
              dp[node] = rank + 1 - seen[to[node]];
              seen[node] = -1;
              remain = dp[node] - 1;
              continue;
            }
            seen[node] = rank;
            q.push_back({node, -1});
            q.push_back({to[node], rank + 1});
          } else {
            seen[node] = -1;
            if (remain) {
              dp[node] = dp[to[node]];
              remain = remain - 1;
            } else {
              dp[node] = dp[to[node]] + 1;
              remain = 0;
            }
          }
        }
        if (dp[i * m + j] > dp[best]) {
          best = i * m + j;
        }
      }
    }
    cout << best / m + 1 << ' ' << best % m + 1 << ' ' << dp[best] << '\n';
  }
}