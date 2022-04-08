#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

constexpr int MAX = 200;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> pos(MAX);
    vector<vector<int>> cnt(MAX, vector<int>(n + 1));
    for (int i = 0, x; i < n; i++) {
      cin >> x, x--, pos[x].push_back(i);
      for (int j = 0; j < MAX; j++) cnt[j][i + 1] = cnt[j][i] + (j == x);
    }
    int res = 1;
    for (int c = 0; c < MAX; c++) {
      int sz = (int)pos[c].size();
      for (int i = 0; i < sz - 1 - i; i++) {
        int j = sz - 1 - i;
        int l = pos[c][i] + 1, r = pos[c][j] - 1;
        int mid = 0;
        if (l <= r) {
          for (int k = 0; k < MAX; k++) {
            mid = max(mid, cnt[k][r + 1] - cnt[k][l]);
          }
        }
        res = max(res, 2 * (i + 1) + mid);
      }
    }
    cout << res << "\n";
  }
}
