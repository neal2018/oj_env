#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, m, k;
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    vector<string> s(n);
    for (auto& x : s) cin >> x;
    for (int i = n - 1; i >= k; i--) {
      for (int j = k; j < m - k; j++) {
        if (s[i][j] == '.') continue;
        int left, right;
        for (left = 0; i - left >= 0 && j - left >= 0 && s[i - left][j - left] != '.'; left++) {
        }
        for (right = 0; i - right >= 0 && j + right < m && s[i - right][j + right] != '.';
             right++) {
        }
        int t = min(left, right);
        if (t <= k) continue;
        for (int tt = 0; tt < t; tt++) {
          s[i - tt][j - tt] = '-';
          s[i - tt][j + tt] = '-';
        }
      }
    }
    bool f = true;
    for (int i = 0; i < n && f; i++)
      for (int j = 0; j < m && f; j++)
        if (s[i][j] == '*') f = false;

    cout << (f ? "YES\n" : "NO\n");
  }
}