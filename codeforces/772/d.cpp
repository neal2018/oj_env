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
  ll n, p;
  cin >> n >> p;
  vector<ll> a(n), good;
  for (auto &x : a) cin >> x;
  sort(a.begin(), a.end());
  set<ll> st;
  for (auto &x : a) {
    if (st.count(x) == 0) {
      ll t = x, f = 1;
      while (t != 0) {
        if (t & 1) {
          t = (t - 1) / 2;
        } else {
          if (t % 4 == 0) {
            t /= 4;
          } else {
            break;
          }
        }
        if (st.count(t)) {
          f = 0;
          break;
        }
      }
      if (f) {
        good.push_back(x);
        st.insert(x);
      }
    }
  }
  vector<Z> res(p + 1);
  res[0] = 0;
  res[1] = upper_bound(good.begin(), good.end(), (1 << 1) - 1) - good.begin();
  for (int i = 2; i <= p; i++) {
    res[i] = res[i - 1] + res[i - 2];
    if (i <= 30) {
      res[i] += upper_bound(good.begin(), good.end(), (1ll << i) - 1) - good.begin();
    } else {
      res[i] += good.size();
    }
  }
  cout << res[p] << "\n";
}
