#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
// #define int ll
constexpr int MAXN = 1e5 + 10, MAX_K = 18;
constexpr ll inf = 1e18;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, k;
  vector<int> phi(MAXN), is_prime(MAXN, 1), primes;
  vector<ll> sum_phi(MAXN + 1);
  for (int i = 2; i < MAXN; i++) {
    if (is_prime[i]) primes.push_back(i), phi[i] = i - 1;
    for (auto& p : primes) {
      if (i * p >= MAXN) break;
      is_prime[i * p] = 0;
      if (i % p == 0) {
        phi[i * p] = phi[i] * p;
        break;
      }
      phi[i * p] = phi[i] * phi[p];
    }
  }
  for (int i = 1; i < MAXN; i++) sum_phi[i + 1] = sum_phi[i] + phi[i];
  auto c = [&](int l, int r) {
    ll res = r - l + 1;
    for (int left = l, right; left <= r; left = right + 1) {
      right = r / (r / left);
      res += 1ll * (right - left + 1) * sum_phi[r / left + 1];
    }
    return res;
  };
  vector dp(MAX_K, vector<ll>(MAXN));
  function<void(int, int, int, int, int)> solve = [&](int l, int r, int opt_l, int opt_r,
                                                      int cur_k) {
    if (l > r) return;
    int mid = (l + r) / 2;
    int best = 0;
    dp[cur_k][mid] = inf;
    for (int i = opt_l; i <= min(mid, opt_r); i++) {
      ll tmp = c(i, mid) + dp[cur_k - 1][i - 1];
      if (tmp < dp[cur_k][mid]) best = i, dp[cur_k][mid] = tmp;
    }
    solve(l, mid - 1, opt_l, best, cur_k), solve(mid + 1, r, best, opt_r, cur_k);
  };
  dp[0][0] = 0;
  for (int i = 1; i < MAXN; i++) dp[0][i] = inf;
  for (int i = 1; i < MAX_K; i++) solve(1, MAXN - 1, 1, MAXN - 1, i);
  cin >> T;
  while (T--) {
    cin >> n >> k;
    if (k >= MAX_K) {
      cout << n << '\n';
    } else {
      cout << dp[k][n] << '\n';
    }
  }
}