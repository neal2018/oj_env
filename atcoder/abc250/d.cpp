#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

constexpr ll MAX_N = 1e6 + 10;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  vector<int> min_primes(MAX_N), primes;
  primes.reserve(1e5);
  for (int i = 2; i < MAX_N; i++) {
    if (!min_primes[i]) min_primes[i] = i, primes.push_back(i);
    for (auto& p : primes) {
      if (p * i >= MAX_N) break;
      min_primes[p * i] = p;
      if (i % p == 0) break;
    }
  }
  vector<ll> pre(MAX_N + 1);
  for (int i = 2; i < MAX_N; i++) {
    pre[i + 1] = pre[i] + (min_primes[i] == i);
  }
  ll n, cnt = 0;
  cin >> n;
  for (ll x : primes) {
    if (x * x * x >= n) {
      break;
    }
    ll t = min(x - 1, n / (x * x * x));
    cnt += pre[t + 1];
    // t <= n / (x*x*x)
  }
  cout << cnt << "\n";
}
