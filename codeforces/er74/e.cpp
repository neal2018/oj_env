#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, m;
  string s;
  cin >> n >> m >> s;
  vector<ll> add(1 << m);
  for (int i = 0; i < n - 1; i++) {
    int x = s[i] - 'a', y = s[i + 1] - 'a';
    add[1 << x]++, add[1 << y]++, add[(1 << x) | (1 << y)] -= 2;
  }
  for (int i = 0; i < m; i++) {
    for (int mask = 0; mask < (1 << m); mask++) {
      if (mask & (1 << i)) add[mask] += add[mask ^ (1 << i)];
    }
  }

  vector<ll> dp(1 << m, 1e18);
  dp[0] = 0;
  for (int mask = 0; mask < (1 << m); mask++) {
    for (int i = 0; i < m; i++) {
      if ((mask & (1 << i)) == 0) {
        dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask] + add[mask]);
      }
    }
  }
  cout << dp.back() << "\n";
}
