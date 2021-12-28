#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  mt19937_64 rng((int)chrono::steady_clock::now().time_since_epoch().count());
  map<ll, ll> prime_hash;
  vector<ll> n_hash(n + 1), f_hash(n + 1);
  vector<int> min_primes(n + 1), primes;
  primes.reserve(1e5);
  for (int i = 2; i <= n; i++) {
    if (!min_primes[i]) min_primes[i] = i, primes.push_back(i), prime_hash[i] = rng();
    for (auto& p : primes) {
      if (i * p > n) break;
      min_primes[i * p] = p;
      if (i % p == 0) break;
    }
  }
  ll rolling = 0;
  for (int i = 2; i <= n; i++) {
    int x = i;
    while (x > 1) {
      n_hash[i] ^= prime_hash[min_primes[x]];
      x /= min_primes[x];
    }
    f_hash[i] = n_hash[i] ^ f_hash[i - 1];
    rolling ^= f_hash[i];
  }
  map<ll, ll> inv_f_hash;
  for (int i = 2; i <= n; i++) inv_f_hash[f_hash[i]] = i;
  auto get_wont = [&]() -> vector<ll> {
    if (rolling == 0) {
      return {};
    } else if (inv_f_hash.count(rolling)) {
      return {inv_f_hash[rolling]};
    } else {
      for (int k = 2; k <= n; k++)
        if (inv_f_hash.count(rolling ^ f_hash[k])) return {k, inv_f_hash[rolling ^ f_hash[k]]};
      return {2, n / 2, n};
    }
  };
  auto wont = get_wont();
  cout << n - wont.size() << "\n";
  for (int i = 1; i <= n; i++)
    if (find(wont.begin(), wont.end(), i) == wont.end()) cout << i << " ";
  cout << "\n";
}
