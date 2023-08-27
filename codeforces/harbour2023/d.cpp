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
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    int res = 0;
    vector<vector<int>> b(n, vector<int>(n));
    vector<int> dia(2 * n), anti_dia(2 * n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        b[i][j] += dia[i + j] + anti_dia[n + i - j];
      }
      for (int j = -n; j < 0; j++) {
        if (i + j < 0) continue;
        b[i][0] += dia[i + j];
      }
      for (int j = 1; j < n; j++) {
        b[i][j] += b[i][j - 1];
      }
      for (int j = 0; j < n; j++) {
        if ((b[i][j] % 2 == 1) ^ (a[i][j] == '1')) {
          res++;
          dia[i + j]++, anti_dia[n + i - j - 1]--;
        }
      }
    }
    cout << res << "\n";
  }
}
