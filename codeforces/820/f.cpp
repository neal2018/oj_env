#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    int w, q;
    cin >> s >> w >> q;
    int n = int(s.size());
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + (s[i] - '0');
    vector<vector<int>> can(9, vector<int>());
    for (int i = 0; i + w <= n; i++) {
      int cur = (pre[i + w] - pre[i] + 9) % 9;
      can[cur].push_back(i);
    }
    while (q--) {
      int l, r, k;
      cin >> l >> r >> k, l--;
      int t = (pre[r] - pre[l] + 9) % 9;
      int res_i = n + 1, res_j = n + 1;
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          if ((i * t + j) % 9 == k && can[i].size() && can[j].size() &&
              (i != j || can[i].size() > 1)) {
            if (i != j) {
              if (pair{res_i, res_j} > pair{can[i][0], can[j][0]}) {
                res_i = can[i][0], res_j = can[j][0];
              }
            } else {
              if (pair{res_i, res_j} > pair{can[i][0], can[i][1]}) {
                res_i = can[i][0], res_j = can[i][1];
              }
            }
          }
        }
      }
      if (res_i == n + 1) {
        cout << "-1 -1\n";
      } else {
        cout << res_i + 1 << " " << res_j + 1 << "\n";
      }
    }
  }
}
