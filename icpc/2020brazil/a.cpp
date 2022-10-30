#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  // E(N) = 1 + \sum E(N-i) *1/(B - A) A<=i<=B
  int n, a, b;
  cin >> n >> a >> b;
  vector<ld> dp(n + 1), pre(n + 2);
  for (int i = 1; i <= min(a, n); i++) {
    dp[i] = 1;
    pre[i + 1] = pre[i] + dp[i];
  }
  auto get = [&](int i) {
    if (i < 0) return (ld)0;
    return pre[i];
  };
  for (int i = a + 1; i <= n; i++) {
    if (a == 0) {
      dp[i] = (1 + (get(i - a) - get(i - b)) * 1.0 / (b - a + 1)) * (ld(b - a + 1) / (b - a));
    } else {
      dp[i] = 1 + (get(i - a + 1) - get(i - b)) * (1.0 / (b - a + 1));
    }
    pre[i + 1] = pre[i] + dp[i];
  }
  cout << dp[n] << "\n";
}
