#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 998244353;
int power(int, ll) = delete;
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
  constexpr int MAX_N = 1e6 + 10;
  vector<int> min_primes(MAX_N), primes;
  primes.reserve(1e5);
  for (int i = 2; i < MAX_N; i++) {
    if (!min_primes[i]) min_primes[i] = i, primes.push_back(i);
    for (auto &p : primes) {
      if (p * i >= MAX_N) break;
      min_primes[p * i] = p;
      if (i % p == 0) break;
    }
  }
  Comb comb(MAX_N);
  int n;
  cin >> n;
  vector<int> a(2 * n);
  map<int, int> mp, mp_prime;
  for (auto &x : a) {
    cin >> x;
    if (min_primes[x] == x) {
      mp_prime[x]++;
    } else {
      mp[x]++;
    }
  }
  if (mp_prime.size() < n) {
    cout << "0\n";
    return 0;
  }
  int extra = n;
  Z res = comb.f[n];
  for (auto &[k, v] : mp) {
    res *= comb.rf[v];
  }
  for (auto &[k, v] : mp_prime) {
    res *= comb.rf[v];
  }

  vector<Z> dp(extra + 1);
  dp[0] = 1;
  for (auto &[k, v] : mp_prime) {
    for (int i = extra; i > 0; i--) {
      dp[i] += dp[i - 1] * v;
    }
  }
  res *= dp[extra];
  cout << res << "\n";
}
