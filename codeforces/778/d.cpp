#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll MAX_N = 2e5 + 1;

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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<int> min_primes(MAX_N + 1), primes;
  primes.reserve(1e5);
  for (int i = 2; i <= MAX_N; i++) {
    if (!min_primes[i]) min_primes[i] = i, primes.push_back(i);
    for (auto &p : primes) {
      if (p * i > MAX_N) break;
      min_primes[p * i] = p;
      if (i % p == 0) break;
    }
  }
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<vector<array<ll, 3>>> g(n);
    for (int i = 0, u, v, x, y; i < n - 1; i++) {
      cin >> u >> v >> x >> y, u--, v--;
      g[u].push_back({v, x, y});
      g[v].push_back({u, y, x});
    }
    vector<int> need(n + 1), cur(n + 1);
    Z res = 0, val = 1;
    function<void(ll, ll)> dfs = [&](ll node, ll fa) {
      res += val;
      for (auto &[ne, x, y] : g[node]) {
        if (ne == fa) continue;
        for (ll t = y; t > 1; t /= min_primes[t]) {
          cur[min_primes[t]]--;
        }
        for (ll t = x; t > 1; t /= min_primes[t]) {
          cur[min_primes[t]]++;
          need[min_primes[t]] = max(need[min_primes[t]], cur[min_primes[t]]);
        }
        val = val * y / x;
        dfs(ne, node);
        val = val * x / y;
        for (ll t = x; t > 1; t /= min_primes[t]) {
          cur[min_primes[t]]--;
        }
        for (ll t = y; t > 1; t /= min_primes[t]) {
          cur[min_primes[t]]++;
        }
      }
    };
    dfs(0, -1);
    for (auto &p : primes) {
      if (p > n) break;
      res *= power(Z(p), need[p]);
    }
    cout << res << "\n";
  }
}
