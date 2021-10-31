#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, a, maxi = 1e7 + 10;
  cin >> T;
  vector<int> min_p(maxi + 1), primes;
  // set<ll> primes;
  for (int i = 2; i <= maxi; i++) {
    if (min_p[i] == 0) {
      min_p[i] = i;
      primes.push_back(i);
    }
    for (auto p : primes) {
      if (i * p > maxi) break;
      min_p[i * p] = p;
      if (i % p == 0) break;
    }
  }
  min_p[0] = 0, min_p[1] = 1;
  auto solve = [&] {
    if (min_p[a] == a || a == 0) {
      cout << 1 << '\n' << a << " = " << a << '\n';
      return;
    } else {
      if (a % 2 == 0) {
        for (auto& p : primes) {
          if (min_p[a - p] == a - p) {
            cout << 2 << '\n' << p << " + " << a - p << " = " << a << '\n';
            return;
          }
        }
      } else {
        if (a > 2 && min_p[a - 2] == a - 2) {
          cout << 2 << '\n' << 2 << " + " << a - 2 << " = " << a << '\n';
          return;
        }
        a -= 1;
        for (auto& p : primes) {
          if (min_p[a - p] == a - p) {
            cout << 3 << '\n' << 1 << " + " << p << " + " << a - p << " = " << a + 1 << '\n';
            return;
          }
        }
      }
    }
  };
  while (T--) {
    cin >> a;
    solve();
  }
}