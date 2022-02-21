#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll MAX_N = 1e6 + 10;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<int> min_primes(MAX_N + 1), primes;
  primes.reserve(1e6);
  for (int i = 2; i <= MAX_N; i++) {
    if (!min_primes[i]) min_primes[i] = i, primes.push_back(i);
    for (auto& p : primes) {
      if (p * i > MAX_N) break;
      min_primes[p * i] = p;
      if (i % p == 0) break;
    }
  }
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cnt(MAX_N + 1);
  for (auto& x : a) cin >> x, cnt[x]++, cnt[x + 1]++;
  for (auto& p : primes) {
    for (int i = MAX_N / p; i; i--) cnt[i] += cnt[i * p];
  }
  int res = 1;
  for (int i = 2; i <= MAX_N; i++) {
    if (cnt[i] == n) {
      res = i;
    }
  }
  cout << res << "\n";
}
