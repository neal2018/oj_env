#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 998244353;
template <typename T>
T power(T a, ll b, int _MOD = MOD, T res = 1) {
  for (; b; b /= 2, (a *= a) %= _MOD)
    if (b & 1) (res *= a) %= _MOD;
  return res;
}
struct Z {
  int x;
  Z(int _x = 0) : x(norm(_x)) {}
  static int norm(int x) {
    if (x < 0) x += MOD;
    if (x >= MOD) x -= MOD;
    return x;
  }
  auto operator<=>(const Z &) const = default;  // need c++ 20
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2, MOD); }
  Z &operator*=(const Z &rhs) { return x = int(ll(x) * rhs.x % MOD), *this; }
  Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  Z &operator%=(const int &rhs) { return x %= rhs, *this; }
  friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  friend Z operator%(Z lhs, const int &rhs) { return lhs %= rhs; }
  friend auto &operator>>(istream &i, Z &z) { return i >> z.x; }
  friend auto &operator<<(ostream &o, const Z &z) { return o << z.x; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    auto func = [&] {
      for (int i = 1; i < n; i++) {
        if (a[i - 1] % a[i]) return Z(0);
      }
      Z res = 1;
      for (int i = 1; i < n; i++) {
        // gcd(a[i-1], b[i]) == a[i]
        // \sum_1^m [gcd(A, i) == B]
        // \sum_1^[m/B] [gcd(A/B, i) == 1]
        ll t = a[i - 1] / a[i], maxi = m / a[i];
        if (t == 1) {
          res *= maxi;
          continue;
        }
        vector<ll> primes;
        for (ll ii = 2; ii * ii <= t; ii++) {
          if (t % ii == 0) {
            primes.push_back(ii);
            while (t % ii == 0) t /= ii;
          }
        }
        if (t > 1) primes.push_back(t);
        ll all = primes.size();
        ll tmp = 0;
        for (ll mask = 0; mask < (1 << all); mask++) {
          ll cnt = __builtin_popcount(mask);
          ll mul = 1;
          for (int j = 0; j < all; j++) {
            if (mask & (1 << j)) mul *= primes[j];
          }
          if (cnt & 1) {
            tmp -= maxi / mul;
          } else {
            tmp += maxi / mul;
          }
        }
        res *= tmp;
      }
      return res;
    };
    cout << func() << "\n";
  }
}
