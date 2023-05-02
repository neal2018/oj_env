#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto get_primes(ll n) {
  vector<ll> min_primes(n + 1), primes;
  for (int i = 2; i < n + 1; i++) {
    if (!min_primes[i]) min_primes[i] = i, primes.push_back(i);
    for (auto& p : primes) {
      if (p * i > n) break;
      min_primes[p * i] = p;
      if (i % p == 0) break;
    }
  }
  return primes;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, max_p;
  cin >> n >> max_p;
  const auto primes = get_primes(max_p);
  vector<ll> u{1}, v{1};
  for (auto p : primes) {
    auto& w = (u.size() < v.size()) ? u : v;
    vector<ll> addon;
    for (auto x : w) {
      auto cur = x * p;
      while (cur <= n) {
        addon.push_back(cur);
        cur *= p;
      }
    }
    w.insert(w.end(), addon.begin(), addon.end());
  }
  sort(u.begin(), u.end());
  sort(v.begin(), v.end());
  ll res = 0;
  for (int i = 0, j = int(v.size()) - 1; i < u.size() && j >= 0; i++) {
    while (u[i] * v[j] > n && j > 0) j--;
    res += (j + 1);
  }
  cout << res << "\n";
}
