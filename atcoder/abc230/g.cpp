#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 2e5 + 10;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<int> mu(n + 1), min_primes(n + 1), primes, pp(n + 1), pre(n + 2);
  primes.reserve(1e5);
  for (int i = 1; i <= n; i++) cin >> pp[i];
  mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!min_primes[i]) min_primes[i] = i, mu[i] = -1, primes.push_back(i);
    for (auto& p : primes) {
      if (p * i > n) break;
      min_primes[p * i] = p;
      if (i % p == 0) break;
      mu[p * i] = -mu[i];
    }
  }
  for (int i = 1; i <= n; i++) pre[i + 1] = pre[i] + mu[i];
  vector<ll> a;
  a.reserve(N);
  vector<vector<int>> d(n + 1);
  for (int i = 1; i <= n; i++) {
    if (!mu[i]) continue;
    for (int j = i; j <= n; j += i) {
      d[j].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (auto x : d[i]) {
      for (auto y : d[pp[i]]) {
        a.push_back(x * N + y);
      }
    }
  }
  sort(a.begin(), a.end());
  ll minus = 0;
  for (ll l = 1, r; l <= n; l = r + 1) {
    r = min(n, n / (n / l));
    minus += (pre[r + 1] - pre[l]) * (n / l) * (n / l);
  }
  ll res = n * n - 2 * minus + (n - 1);
  if (pp[1] != 1) res--;
  ll sz = a.size();
  for (int i = 0, j; i < sz; i = j) {
    j = i;
    while (j < sz && a[i] == a[j]) j++;
    ll k = a[i], v = j - i;
    res += mu[k / N] * mu[k % N] * v * v;
  }
  cout << res / 2 << "\n";
}