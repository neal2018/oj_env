#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;

constexpr ll norm(ll x) { return (x % MOD + MOD) % MOD; }
template <class T>
constexpr T power(T a, ll b, T res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}
struct Z {
  ll x;
  constexpr Z(ll _x = 0) : x(norm(_x)) {}
  // auto operator<=>(const Z &) const = default; // cpp20 only
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

struct SegTree {
  ll n;
  vector<ll> t;
  SegTree(ll _n) : n(_n), t(2 * n) {}
  void modify(ll p, ll v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = t[2 * p] & t[2 * p + 1];
  }
  ll query(ll l, ll r) {
    ll res = (1ll << 60) - 1;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res &= t[l++];
      if (r & 1) res &= t[--r];
    }
    return res;
  }
};

int main() {
  ll n, all = (1ll << 60) - 1;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a) cin >> x, all &= x;
  SegTree seg(n);
  for (ll i = 0; i < n; i++) seg.t[i + n] = a[i];
  for (ll i = n - 1; i > 0; i--) seg.t[i] = seg.t[2 * i] & seg.t[2 * i + 1];
  vector<Z> dp(n + 1), pre(n + 2);
  dp[0] = 1, pre[1] = 1;
  auto work = [&](ll _n) {
    ll left = 0;
    for (ll i = 0; i < _n; i++) {
      while (seg.query(left, i + 1) == 0) left++;
      // left ... i is 1
      dp[i + 1] = pre[i + 1] - pre[left];
      pre[i + 2] = pre[i + 1] + dp[i + 1];
    }
  };
  work(n);
  Z res = dp[n];
  for (ll i = n - 1, t = a[0]; i > 0; i--) {
    ll nex = t & a[i];
    if (!nex) break;
    if (nex != t) seg.modify(0, nex), work(i);
    res += dp[i];
    if (all) res -= 1;
    t = nex;
  }
  cout << res << "\n";
}