#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;
template <typename T>
T power(T a, ll b, ll _MOD = MOD, T res = 1) {
  for (; b; b /= 2, (a *= a) %= _MOD)
    if (b & 1) (res *= a) %= _MOD;
  return res;
}
struct Z {
  ll x;
  Z(ll _x = 0) : x(norm(_x)) {}
  static ll norm(ll x) { return (x % MOD + MOD) % MOD; }
  auto operator<=>(const Z &) const = default;  // need c++ 20
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2, MOD); }
  Z &operator*=(const Z &rhs) { return x = x * rhs.x % MOD, *this; }
  Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  Z &operator%=(const ll &rhs) { return x %= rhs, *this; }
  friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  friend Z operator%(Z lhs, const ll &rhs) { return lhs %= rhs; }
  friend auto &operator>>(istream &i, Z &z) { return i >> z.x; }
  friend auto &operator<<(ostream &o, const Z &z) { return o << z.x; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> id(n);
    for (int x; auto i : views::iota(0, n)) {
      cin >> x, id[x] = i;
    }
    Z res = 1;
    if (n <= 2) {
      cout << res << "\n";
      continue;
    }
    auto [l, r] = minmax({id[0], id[1]});
    int avail = r - l + 1 - 2;
    for (int i = 2; i < n; i++) {
      if (l <= id[i] && id[i] <= r) {
        res *= avail, avail--;
      } else {
        if (id[i] < l) {
          avail += (l - id[i] + 1 - 2);
          l = id[i];
        } else {
          avail += (id[i] - r + 1 - 2);
          r = id[i];
        }
      }
    }
    cout << res << "\n";
  }
}
