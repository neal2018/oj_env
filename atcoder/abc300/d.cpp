#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power5(ll a) { return a * a * a * a * a; }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  constexpr ll MAX_N = 1e6 + 10;
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
  ll n, res = 0;
  cin >> n;
  for (int i = 0; i < primes.size(); i++) {
    auto a = primes[i];
    if (power5(a) > n) {
      break;
    }
    for (int j = i + 1; j < primes.size(); j++) {
      auto b = primes[j];
      if (a * a * b * b * b > n) break;
      for (int k = j + 1; k < primes.size(); k++) {
        auto c = primes[k];
        if (a * a * b * c * c > n) break;
        res++;
      }
    }
  }
  cout << res << "\n";
}
