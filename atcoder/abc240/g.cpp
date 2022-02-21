#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MAX_N = 1e6 + 10;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
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
  map<int, array<ll, 3>> mp;
  for (auto& p : primes) {
    mp[p][0] = rng();
    mp[p][1] = rng();
    mp[p][2] = mp[p][0] ^ mp[p][1];
  }
  map<int, int> cnt;
  ll n, q, cur = 0, x;
  cin >> n >> q;
  vector<ll> b(n + 1);
  for (int i = 0; i < n; i++) {
    vector<int> ps;
    cin >> x;
    while (x != 1) {
      int p = min_primes[x];
      ps.push_back(p);
      x = x / p;
    }
    for (auto& p : ps) {
      cur ^= mp[p][cnt[p] % 3];
      cnt[p]++;
    }
    b[i + 1] = cur;
  }
  while (q--) {
    ll l, r;
    cin >> l >> r;
    if (b[l - 1] == b[r]) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}