#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll MOD = 1e9 + 7;

ll norm(ll x) { return (x % MOD + MOD) % MOD; }
template <class T>
T power(T a, ll b, T res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}
struct Z {
  ll x;
  Z(ll _x = 0) : x(norm(_x)) {}
  auto operator<=>(const Z &) const = default;
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2); }
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
  ll h, w;
  cin >> h >> w;
  vector<string> s(h + 1, string(w + 1, '?'));
  for (int i = 0, x; i < h; i++) {
    cin >> x;
    for (int j = 0; j < x; j++) s[i][j] = 'B';
    s[i][x] = 'W';
  }
  int nice = 1;
  for (int i = 0, x; i < w; i++) {
    cin >> x;
    for (int j = 0; j < x; j++) {
      if (s[j][i] == 'W') nice = 0;
      s[j][i] = 'B';
    }
    if (s[x][i] == 'B') nice = 0;
    s[x][i] = 'W';
  }
  if (nice == 0) {
    cout << "0\n";
    return 0;
  }
  ll cnt = 0, remain = h * w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cnt += s[i][j] == '?';
    }
  }
  cout << power(Z(2), cnt) << "\n";
}
