#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
constexpr int N = 2 * 1e7;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> min_primes(N + 1), primes;
  primes.reserve(1e5);
  for (int i = 2; i <= N; i++) {
    if (!min_primes[i]) min_primes[i] = i, primes.push_back(i);
    for (auto& p : primes) {
      if (i * p > N) break;
      min_primes[i * p] = p;
      if (i % p == 0) break;
    }
  }
  vector<ll> cnt(N + 1), dp(N + 1);
  for (int i = 0, x; i < n; i++) cin >> x, cnt[x]++;
  for (auto& p : primes)
    for (int i = N / p; i >= 1; i--) cnt[i] += cnt[i * p];
  ll res = 0;
  dp[1] = cnt[1];
  for (int i = 1; i <= N; i++) {
    for (auto& p : primes) {
      if (i * p > N) break;
      dp[i * p] = max(dp[i * p], dp[i] + cnt[i * p] * (i * p - i));
    }
    res = max(res, dp[i]);
  }
  cout << res << '\n';
}