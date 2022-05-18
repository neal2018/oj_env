#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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

constexpr int SZ = 17;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, q;
  string s;
  cin >> n >> s >> q;
  ll ques_cnt = count(s.begin(), s.end(), '?');
  vector<string> queries(q);
  vector<Z> res(q);
  vector<vector<ll>> patch(SZ + 1);
  for (int i = 0; i < q; i++) {
    cin >> queries[i];
    patch[queries[i].size()].push_back(i);
  }
  for (int sz = 1; sz <= SZ; sz++) {
    if (patch[sz].size() == 0) continue;
    vector<Z> a(1 << SZ);
    for (int i = 0; i < n; i++) {
      {
        ll matched = 0, cnt = ques_cnt, mask = 0;
        for (int j = 0; j < n; j++) {
          if (i - j < 0 || i + j >= n) break;
          // [i-j, i+j]
          if (s[i - j] == '?' && s[i - j] == s[i + j]) matched++;
          if (s[i - j] == '?') cnt--;
          if (j && s[i + j] == '?') cnt--;
          if (s[i - j] != s[i + j]) {
            if (s[i - j] != '?' && s[i + j] != '?') break;
            char c = s[i - j] ^ s[i + j] ^ '?';
            mask |= 1ll << (c - 'a');
          }
          a[mask] += power(Z(sz), matched + cnt);
        }
      }
      if (i > 0) {
        ll matched = 0, cnt = ques_cnt, mask = 0;
        for (int j = 0; j < n; j++) {
          if (i - j - 1 < 0 || i + j >= n) break;
          // [i-j-1, i+j]
          if (s[i - j - 1] == '?' && s[i - j - 1] == s[i + j]) matched++;
          if (s[i - j - 1] == '?') cnt--;
          if (s[i + j] == '?') cnt--;
          if (s[i - j - 1] != s[i + j]) {
            if (s[i - j - 1] != '?' && s[i + j] != '?') break;
            char c = s[i - j - 1] ^ s[i + j] ^ '?';
            mask |= 1ll << (c - 'a');
          }
          a[mask] += power(Z(sz), matched + cnt);
        }
      }
    }
    // sosdp
    auto f = a;
    for (int i = 0; i < SZ; i++) {
      for (int mask = 0; mask < (1 << SZ); mask++) {
        if (mask & (1 << i)) f[mask] += f[mask ^ (1 << i)];
      }
    }
    for (auto &id : patch[sz]) {
      ll mask = 0;
      for (auto &c : queries[id]) mask |= 1ll << (c - 'a');
      res[id] = f[mask];
    }
  }
  for (auto &x : res) cout << x << "\n";
}
