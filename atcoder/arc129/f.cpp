#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MOD = 998244353;
constexpr int MAX_N = 60;

ll power(ll a, ll b, ll res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  constexpr ll MOD = 998244353;
  constexpr int maxi = MOD + 1;
  vector<int> min_p(maxi + 1), phi(maxi + 1), primes;
  phi[1] = 1;
  for (int i = 2; i <= maxi; i++) {
    if (min_p[i] == 0) {
      min_p[i] = i;
      primes.push_back(i);
      phi[i] = i - 1;
    }
    for (auto p : primes) {
      if (i * p > maxi) break;
      min_p[i * p] = p;
      if (i % p == 0) {
        phi[i * p] = phi[i] * p;
        break;
      }
      phi[i * p] = phi[i] * phi[p];
    }
  }
  cout << phi[MOD - 1] << endl;
}