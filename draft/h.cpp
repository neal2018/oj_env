#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int M = 2e6 + 10, MOD = 1e9 + 7;
struct C {
  int f[M] = {1}, rf[M] = {1}, inv[M] = {};
  constexpr C() {
    f[1] = 1, rf[1] = 1, inv[1] = 1;
    for (int i = 2; i < M; i++) {
      inv[i] = 1ll * (MOD - MOD / i) * inv[MOD % i] % MOD;
      f[i] = 1ll * f[i - 1] * i % MOD;
      rf[i] = 1ll * rf[i - 1] * inv[i] % MOD;
    }
  }
};

int main() {
  const C c = C();
  int h, w, n;
  cin >> h >> n;
  w = h;
  int x[n + 1], y[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    x[i]--, y[i]--;
  }
  x[n] = h - 1, y[n] = w - 1;
  int order[n + 1];
  iota(order, order + n + 1, 0);
  sort(order, order + n + 1,
       [&](int a, int b) { return x[a] == x[b] ? y[a] < y[b] : x[a] < x[b]; });
  int dp[n + 1];  // dp[i]: number of path from [0,0] to [xi, yi]
  for (int i = 0; i <= n; i++) {
    int k = order[i];
    dp[i] = 1ll * c.f[x[k] + y[k]] * c.rf[x[k]] % MOD * c.rf[y[k]] % MOD;
    // (xi+yi chose xi) = (xi+yi)!/(xi!yi!)
    for (int j = 0; j < i; j++) {
      int dx = x[k] - x[order[j]], dy = y[k] - y[order[j]];
      if (dx < 0 || dy < 0) continue;
      dp[i] =
          (MOD + dp[i] - 1ll * dp[j] * c.f[dx + dy] % MOD * c.rf[dx] % MOD * c.rf[dy] % MOD) % MOD;
    }
  }
  cout << dp[n] << endl;
}
