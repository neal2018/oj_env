#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  constexpr ll MAX_N = 4e4, MOD = 1000000007;
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
  ll l, r;
  cin >> l >> r;
  vector<ll> cnt(MAX_N + 1);
  for (ll i = l; i <= r; i++) {
    if (min_primes[i] != i) {
      map<ll, ll> mp;
      ll x = i;
      while (x > 1) {
        mp[min_primes[x]]++;
        x /= min_primes[x];
      }
      for (auto& [k, v] : mp) {
        cnt[k] = max(cnt[k], v);
      }
    }
  }
  if (accumulate(cnt.begin(), cnt.end(), 0ll) == 0) {
    cout << -1 << "\n";
  } else {
    ll res = 1;
    for (int i = 1; i <= MAX_N; i++) {
      for (int _ = 0; _ < cnt[i]; _++) {
        res = (res * i) % MOD;
      }
    }
    cout << res << "\n";
  }
}
