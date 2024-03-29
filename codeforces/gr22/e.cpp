#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;
template <typename T>
constexpr T power(T a, ll b, ll _MOD = MOD, T res = 1) {
  for (; b; b /= 2, (a *= a) %= _MOD)
    if (b & 1) (res *= a) %= _MOD;
  return res;
}
struct Z {
  ll x;
  constexpr Z(ll _x = 0) : x(norm(_x)) {}
  constexpr static ll norm(ll x) { return (x % MOD + MOD) % MOD; }
  constexpr auto operator<=>(const Z &) const = default;  // need c++ 20
  constexpr Z operator-() const { return Z(norm(MOD - x)); }
  constexpr Z inv() const { return power(*this, MOD - 2, MOD); }
  constexpr Z &operator*=(const Z &rhs) { return x = x * rhs.x % MOD, *this; }
  constexpr Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  constexpr Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  constexpr Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  constexpr Z &operator%=(const ll &rhs) { return x %= rhs, *this; }
  constexpr friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  constexpr friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  constexpr friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  constexpr friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  constexpr friend Z operator%(Z lhs, const ll &rhs) { return lhs %= rhs; }
  friend auto &operator>>(istream &i, Z &z) { return i >> z.x; }
  friend auto &operator<<(ostream &o, const Z &z) { return o << z.x; }
};


constexpr int MAX_N = 5e5;

struct Comb {
  vector<Z> f, rf;
  Comb(int n = 2) : f(n, 1), rf(n, 1) { fill(2, n); }
  void fill(int start, int n) {
    f.resize(n), rf.resize(n);
    for (int i = start; i < n; i++) f[i] = f[i - 1] * i;
    rf[n - 1] = power(f[n - 1], MOD - 2);
    for (int i = n - 2; i >= start; i--) rf[i] = rf[i + 1] * (i + 1);
  }
  Z binom(int n, int r) {
    if (n < 0 || r < 0 || n < r) return 0;
    if (f.size() <= n) fill(int(f.size()), n + 1);
    return f[n] * rf[n - r] * rf[r];
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Comb comb;
  int n;
  cin >> n, n++;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  Z res = 0;
  for (auto i : views::iota(0, n)) {
    if (a[i] == 0) break;
    res += comb.binom(a[i] + i, a[i] - 1);
  }
  cout << res << "\n";
}
