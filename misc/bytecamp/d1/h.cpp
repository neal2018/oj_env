#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n, n++;
  vector<string> a(3);
  for (auto& x : a) cin >> x;
  a[0] += ".", a[1] += ".", a[2] += ".";
  vector<int> dp(n + 1, 1e9);
  dp[0] = 0;
  vector<string> one = {".#.", "##.", ".#."};
  vector<string> zero = {"###.", "#.#.", "###."};
  for (int i = 2; i < n; i++) {
    if (i >= 2) {
      int cnt = 0;
      for (int ii = 0; ii < 3; ii++) {
        for (int jj = 0; jj < 3; jj++) {
          cnt += (a[jj][i - 2 + ii] != one[jj][ii]);
        }
      }
      dp[i + 1] = min(dp[i + 1], dp[i - 2] + cnt);
    }
    if (i >= 3) {
      int cnt = 0;
      for (int ii = 0; ii < 4; ii++) {
        for (int jj = 0; jj < 3; jj++) {
          cnt += (a[jj][i - 3 + ii] != zero[jj][ii]);
        }
      }
      dp[i + 1] = min(dp[i + 1], dp[i - 3] + cnt);
    }
  }
  cout << dp[n] << "\n";
}
