#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll MAX_N = 2e5 + 10, LOG_N = 20;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<int> min_primes(MAX_N + 1), primes;
  primes.reserve(1e5);
  for (int i = 2; i <= MAX_N; i++) {
    if (!min_primes[i]) min_primes[i] = i, primes.push_back(i);
    for (auto& p : primes) {
      if (p * i > MAX_N) break;
      min_primes[p * i] = p;
      if (i % p == 0) break;
    }
  }
  ll prime_cnt = primes.size();
  map<int, int> p2id;
  for (int i = 0; i < prime_cnt; i++) {
    p2id[primes[i]] = i;
  }
  vector<vector<int>> cnt(prime_cnt, vector<int>(LOG_N));
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  for (auto x : a) {
    map<int, int> mp;
    while (x != 1) {
      mp[min_primes[x]]++, x /= min_primes[x];
    }
    for (auto& [k, v] : mp) {
      cnt[p2id[k]][v]++;
    }
  }
  ll res = 1;
  for (int i = 0; i < prime_cnt; i++) {
    ll pre = 0;
    for (int j = LOG_N - 1; j >= 0; j--) {
      pre += cnt[i][j];
      if (pre >= n - 1) {
        for (int k = 0; k < j; k++) res *= primes[i];
        break;
      }
    }
  }
  cout << res << "\n";
}
