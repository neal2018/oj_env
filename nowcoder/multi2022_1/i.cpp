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
  // auto operator<=>(const Z &) const = default;  // need c++ 20
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

int REMAIN = 123;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector dp(8, vector(136, Z(0)));
  Comb comb(2000);
  for (int i = 6; i >= 0; i--) {
    // need
    int need = (13 - i * 2) * 3;
    for (int j = need; j <= REMAIN; j++) {
      Z d = 0;
      for (int k = 1; k <= j - need + 1; k++) {
        Z p = (comb.binom(j - need, k - 1) * comb.f[k - 1] * need * comb.f[j - k]);
        dp[i][j] += (dp[i + 1][j - k] + k) * p;
        d += p;
      }
      dp[i][j] /= comb.f[j];
      d /= comb.f[j];
    }
  }

  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    string s;
    cin >> s;
    set<string> st;
    for (int ii = 0; ii < 26; ii += 2) {
      st.insert(s.substr(ii, 2));
    }
    ll already = (13 - st.size());
    cout << "Case #" << i + 1 << ": " << dp[already][REMAIN] << "\n";
  }
}
