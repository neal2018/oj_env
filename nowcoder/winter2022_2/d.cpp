#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

constexpr int MAX = 1e6;

constexpr ll MAX_N = 1e6 + 10;
int main() {
  constexpr ll MOD = 998244353;
  constexpr int maxi = 1e9;
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
  // vector<ld> stk;
  // vector<ll> id;
  // for (int i = 2; i <= maxi; i++) {
  //   ld cur = (ld)phi[i] / i;
  //   if (!stk.size() || cur > stk.back()) {
  //     stk.push_back(cur);
  //     id.push_back(i);
  //     // stk.pop_back();
  //     // id.pop_back();
  //   }
  // }
  // cout << stk.size() << "\n";
  cout << primes.size() << "\n";
  ll mm = 0;
  for (int i = 0; i < primes.size() - 1; i++) {
    mm = max(mm, (ll)primes[i + 1] - primes[i]);
  }
  cout << mm << '\n';
  // for (auto& x : id) cout << x << ", ";
  // cout<<"\n";
  // for (auto& x : stk) cout << x << ", ";
  // cout<<"aaa";
}