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

constexpr ll inf = 2e9;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<array<ll, 2>> a(n);
  for (ll cur = 0; auto &[x, y] : a) {
    cin >> x, y = -1;
    if (x == 1) {
      cin >> y;
    } else if (x == 2) {
      cin >> y, cur += y, cur = min(cur, inf);
    } else if (x == 3) {
      y = cur, cur *= 2, cur = min(cur, inf);
    }
  }
  reverse(a.begin(), a.end());
  Z res = 0, mul = 1;
  ll minus = 0;
  vector<ll> attack;
  for (auto [x, y] : a) {
    if (x == 1) {
      if (y <= minus) continue;
      y -= minus;
      Z add = 1;
      for (int i = int(attack.size()) - 1; auto k : attack) {
        if (y > k) add += power(Z(2), i), y -= k;
        i--;
      }
      res += add * mul;
    } else if (x == 2) {
      minus += y, minus = min(minus, inf);
    } else {
      if (y == 0) {
        mul *= 2;
      } else if (y < inf) {
        attack.push_back(y);
      }
    }
  }
  cout << res << "\n";
}
