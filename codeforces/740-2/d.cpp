#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define LOCAL

int main() {
#ifdef LOCAL
  ifstream cin("/Users/neallai/Projects/oj_env/input.txt");
  ofstream cout("/Users/neallai/Projects/oj_env/output.txt");
#endif  // LOCAL
  ll n, m, sum = 0;
  cin >> n >> m;
  vector<ll> dp(n + 1), c(n + 1);
  for (ll i = 1; i <= n; i++) {
    (sum += c[i]) %= m;
    dp[i] = (i == 1 ? 1 : sum);
    for (int j = 2; i * j <= n; j++) {
      (c[i * j] += dp[i]) % m;
      if (i * j + j <= n) (c[i * j + j] += m - dp[i]) %= m;
    }
    (sum += dp[i]) %= m;
  }
  cout << dp[n] << endl;
}