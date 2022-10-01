#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, s;
  cin >> n >> s;
  vector<int> v(n), flip(n);
  for (int i = 0, a, b; i < n; i++) {
    cin >> a >> b;
    if (a > b) {
      flip[i] = 1, swap(a, b);
    }
    s -= a, v[i] = b - a;
  }
  if (s < 0) {
    cout << "No\n";
    return 0;
  }
  vector tran(n, vector(s + 1, -1));
  vector<int> dp(s + 1);
  dp[0] = 1;
  for (int id = 0; id < n; id++) {
    for (int i = s; i >= v[id]; i--) {
      if (dp[i] == 0 && dp[i - v[id]] == 1) {
        dp[i] = 1;
        tran[id][i] = i - v[id];
      }
    }
  }
  if (dp[s] == 0) {
    cout << "No\n";
    return 0;
  } else {
    cout << "Yes\n";
    int j = s;
    for (int i = n - 1; i >= 0; i--) {
      auto pre = tran[i][j];
      if (pre >= 0) {
        flip[i] ^= 1;
        j = pre;
      }
    }
    for (auto&& x : flip) cout << (x ? 'T' : 'H');
    cout << "\n";
  }
}
