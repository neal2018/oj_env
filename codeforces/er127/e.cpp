#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
// https://space.bilibili.com/672328094

constexpr ll MOD = 998244353;

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

using Hash = pair<ull, ull>;

constexpr Hash mod = {1000000069, 1000000067};

Hash operator*(const Hash &a, const Hash &b) {
  return {a.first * b.first % mod.first, a.second * b.second % mod.second};
}

Hash operator+(const Hash &a, const Hash &b) {
  return {(a.first + b.first) % mod.first, (a.second + b.second) % mod.second};
}

Hash operator*(const Hash &a, const ull &b) {
  return {a.first * b % mod.first, a.second * b % mod.second};
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  ll n;
  cin >> n;
  string s;
  cin >> s;
  n = s.size();
  Hash base = {rng(), rng()};
  vector<Hash> hash(n + 1);
  hash[0] = {1, 1};
  for (int i = 1; i <= n; i++) hash[i] = hash[i - 1] * base;
  vector<Hash> a(n);
  vector<ll> len(n);
  ll cnt = 0;
  for (ll i = n - 1; i >= 0; i--) {
    if (2 * i + 1 >= n) {
      a[i] = hash[0] * ((s[i] == 'A') + 1);
      len[i] = 1;
    } else {
      if (a[2 * i + 1] != a[2 * i + 2]) cnt++;
      auto [x, y] = minmax(a[2 * i + 1], a[2 * i + 2]);
      auto child_len = len[2 * i + 1];
      a[i] = hash[2 * child_len] * ((s[i] == 'A') + 1) + hash[child_len] * x + y;
      len[i] = 2 * child_len + 1;
    }
  }
  cout << power(Z(2), cnt) << "\n";
}
