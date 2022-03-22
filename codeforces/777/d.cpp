#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
// https://space.bilibili.com/672328094

ll power(ll a, ll b, ll MOD = 1, ll res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}

bool is_prime(ll n) {
  if (n < 2) return false;
  static constexpr int A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
  int s = __builtin_ctzll(n - 1);
  ll d = (n - 1) >> s;
  for (auto a : A) {
    if (a == n) return true;
    ll x = power(a, d, n);
    if (x == 1 || x == n - 1) continue;
    bool ok = false;
    for (int i = 0; i < s - 1; ++i) {
      x = x * x % n;  // potential overflow!
      if (x == n - 1) {
        ok = true;
        break;
      }
    }
    if (!ok) return false;
  }
  return true;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll x, d;
    cin >> x >> d;
    ll k = 0;
    ll c = x;
    while (c % d == 0) {
      c /= d, k++;
    }
    if (k < 2) {
      cout << "NO\n";
      continue;
    }
    int is_c = is_prime(c);
    if (c != 1 && !is_c) {
      cout << "YES\n";
      continue;
    }
    int is_d = is_prime(d);
    if (is_d) {
      cout << "NO\n";
      continue;
    }
    if (k > 3) {
      cout << "YES\n";
      continue;
    }
    if (k == 3) {
      int f = 0;
      for (int i = 2; i * i <= d; i++) {
        if (d % i == 0) {
          if ((i * c) % d != 0) {
            f = 1;
          }
          if (((d / i) * c) % d != 0) {
            f = 1;
          }
        }
      }
      cout << (f ? "YES\n" : "NO\n");
      continue;
    }
    cout << "NO\n";
  }
}
