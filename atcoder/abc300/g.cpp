#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  constexpr ll MAX_N = 100;
  vector<ll> min_primes(MAX_N), primes;
  primes.reserve(1e5);
  for (int i = 2; i < MAX_N; i++) {
    if (!min_primes[i]) min_primes[i] = i, primes.push_back(i);
    for (auto& p : primes) {
      if (p * i >= MAX_N) break;
      min_primes[p * i] = p;
      if (i % p == 0) break;
    }
  }
  cout << primes.size();
}
