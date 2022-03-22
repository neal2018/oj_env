#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr int L = 5;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    ll n;
    string s;
    cin >> n >> s;
    auto check = [&](int mask, int add) {
      mask = 2 * mask + add;
      string t(L + 1, '0');
      for (int i = 0; i <= L; i++) t[i] = (mask >> i & 1) ? '1' : '0';
      if (t == string(t.rbegin(), t.rend())) return 0;
      auto pre = t.substr(0, L);
      if (pre == string(pre.rbegin(), pre.rend())) return 0;
      return 1;
    };
    array<array<int, 2>, 1 << L> memo;
    for (int i = 0; i < (1 << L); i++) {
      memo[i] = {check(i, 0), check(i, 1)};
    }
    // dp[i][t] is able to make s[0...i] ends with t
    vector<vector<int>> dp(n + 1, vector<int>(1 << L));
    dp[0] = vector<int>(1 << L, 1);
    for (int i = 0; i < n; i++) {
      for (int mask = 0; mask < (1 << L); mask++) {
        if (dp[i][mask]) {
          if ((s[i] == '0' || s[i] == '?') && (memo[mask][0] || i < L - 1)) {
            dp[i + 1][(mask * 2) % (1 << L)] = 1;
          }
          if ((s[i] == '1' || s[i] == '?') && (memo[mask][1] || i < L - 1)) {
            dp[i + 1][(mask * 2 + 1) % (1 << L)] = 1;
          }
        }
      }
    }
    int f = 0;
    for (int i = 0; i < (1 << L); i++) {
      f |= dp[n][i];
    }
    cout << (f ? "POSSIBLE\n" : "IMPOSSIBLE\n");
  }
}
