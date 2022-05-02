#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 998244353;

int main() {
  ll n, t;
  cin >> n >> t;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll z = t + 1, zz = 1;
  for (ll i = n - 1; i >= 1; i--) {
    z = z + 1 - a[i];
    zz = zz * z % MOD;
  }
  zz = zz * (t + 1 - accumulate(a.begin(), a.end(), 0ll)) % MOD;
  cout << zz << "\n";
}
