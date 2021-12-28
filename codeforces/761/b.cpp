#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  constexpr ll N = 1e5;
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
  auto f = [&]() {
    cin >> n;
    if (n % 2 == 0) {
      cout << 2 << " " << n - 3 << " " << 1 << '\n';
    } else {
      ll i = 1;
      n--;
      while (n % primes[i] == 0) i++;
      cout << primes[i] << " " << n - primes[i] << " " << 1 << '\n';
    }
  };
  while (T--) f();
}