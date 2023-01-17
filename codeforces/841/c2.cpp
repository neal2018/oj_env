#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr __int128 MOD = 9223372036737335297;

constexpr __int128 norm(__int128 x) { return x < 0 ? (x + MOD) % MOD : x % MOD; }
template <class T>
constexpr T power(T a, __int128 b, T res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}
struct Z {
  __int128 x;
  constexpr Z(__int128 _x = 0) : x(norm(_x)) {}
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2); }
  auto operator<=>(const Z &) const = default;
  Z &operator*=(const Z &rhs) { return x = x * rhs.x % MOD, *this; }
  Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  Z &operator%=(const __int128 &rhs) { return x %= rhs, *this; }
  friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  friend Z operator%(Z lhs, const __int128 &rhs) { return lhs %= rhs; }
  friend auto operator<=>(Z lhs, const Z &rhs) { return lhs.x <=> rhs.x; }
};

namespace fwt {
void fwt_or(vector<Z> &a, int opt) {
  int n = int(a.size());
  for (int mid = 1; mid < n; mid *= 2) {
    for (int i = 0; i < n; i += 2 * mid) {
      for (int j = 0; j < mid; j++) {
        a[i + j + mid] = opt == 1 ? (a[i + j] + a[i + j + mid]) : (a[i + j + mid] - a[i + j]);
      }
    }
  }
}
void fwt_and(vector<Z> &a, int opt) {
  int n = int(a.size());
  for (int mid = 1; mid < n; mid *= 2) {
    for (int i = 0; i < n; i += 2 * mid) {
      for (int j = 0; j < mid; j++) {
        a[i + j] = opt == 1 ? (a[i + j] + a[i + j + mid]) : (a[i + j] - a[i + j + mid]);
      }
    }
  }
}
void fwt_xor(vector<Z> &a, int opt) {
  int n = int(a.size());
  auto inv2 = (MOD + 1) / 2;
  for (int mid = 1; mid < n; mid *= 2) {
    for (int i = 0; i < n; i += 2 * mid) {
      for (int j = 0; j < mid; j++) {
        auto x = a[i + j], y = a[i + j + mid];
        a[i + j] = x + y, a[i + j + mid] = x - y;
        if (opt != 1) a[i + j] *= inv2, a[i + j + mid] *= inv2;
      }
    }
  }
}
};  // namespace fwt

vector<Z> mul(vector<Z> a, vector<Z> b, function<void(vector<Z> &, int)> f) {
  f(a, 1), f(b, 1);
  for (int i = 0; i < a.size(); i++) a[i] = a[i] * b[i];
  f(a, -1);
  return a;
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int sz = 1;
    while (sz <= n) sz *= 2;
    vector<Z> freq(sz);
    freq[0] = 1;
    for (int cur = 0; auto &x : a) {
      cur ^= x, freq[cur] += 1;
    }
    auto f = mul(freq, freq, fwt::fwt_xor);
    ll res = 0;
    for (auto &x : f) res += x.x;
    for (ll i = 0; i * i < sz; i++) res -= f[i * i].x;
    cout << res / 2 << "\n";
  }
}
