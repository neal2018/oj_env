#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto popcount(ll x) { return __builtin_popcount(x); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto bf = [](ll n, ll k) {
    ll res = 0;
    for (ll a = 0; a < (1 << n); a++) {
      for (ll b = 0; b < (1 << n); b++) {
        if (popcount(a) + popcount(b) - popcount(a + b) == k) {
          res++;
        }
      }
    }
    return res;
  };
  for (int n = 1; n < 12; n++) {
    for (int k = 0; k < n; k++) {
      cout << bf(n, k) << " ";
    }
    cout << "\n";
  }
}
