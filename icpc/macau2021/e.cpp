#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094
using i128 = __int128;
constexpr i128 MOD = 9223372036737335297;

constexpr i128 norm(i128 x) { return x < 0 ? (x + MOD) % MOD : x % MOD; }
template <typename T>
constexpr T power(T a, i128 b, T res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD) {
    if (b & 1) (res *= a) %= MOD;
  }
  return res;
}

struct Z {
  i128 x;
  constexpr Z(i128 _x = 0) : x(norm(_x)) {}
  Z operator-() const { return Z(MOD - x); }
  Z inv() const { return power(*this, MOD - 1); }
  Z& operator*=(const Z& rhs) { return x = x * rhs.x % MOD, *this; }
  Z& operator+=(const Z& rhs) { return x = norm(x + rhs.x), *this; }
  Z& operator-=(const Z& rhs) { return x = norm(x - rhs.x), *this; }
  Z& operator/=(const Z& rhs) { return *this *= rhs.inv(); }
  Z& operator%=(const ll& rhs) { return x %= rhs, *this; }
  friend Z operator*(Z lhs, const Z& rhs) { return lhs *= rhs; }
  friend Z operator+(Z lhs, const Z& rhs) { return lhs += rhs; }
  friend Z operator-(Z lhs, const Z& rhs) { return lhs -= rhs; }
  friend Z operator/(Z lhs, const Z& rhs) { return lhs /= rhs; }
};

void ntt(vector<Z>& a, int f) {
  int n = int(a.size());
  vector<Z> w(n);
  vector<int> rev(n);
  for (int i = 0; i < n; i++) rev[i] = (rev[i / 2] / 2) | ((i & 1) * (n / 2));
  for (int i = 0; i < n; i++) {
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  }
  Z wn = power(f ? (MOD + 1) / 3 : 3, (MOD - 1) / n);
  w[0] = 1;
  for (int i = 1; i < n; i++) w[i] = w[i - 1] * wn;
  for (int mid = 1; mid < n; mid *= 2) {
    for (int i = 0; i < n; i += 2 * mid) {
      for (int j = 0; j < mid; j++) {
        Z x = a[i + j], y = a[i + j + mid] * w[n / (2 * mid) * j];
        a[i + j] = x + y, a[i + j + mid] = x - y;
      }
    }
  }
  if (f) {
    Z iv = power(Z(n), MOD - 2);
    for (auto& x : a) x *= iv;
  }
}

vector<Z> mul(vector<Z>& a, vector<Z>& b) {
  int n = 1, m = int(a.size()) + int(b.size()) - 1;
  while (n < m) n *= 2;
  a.resize(n), b.resize(n);
  ntt(a, 0), ntt(b, 0);
  for (int i = 0; i < n; i++) a[i] *= b[i];
  ntt(a, 1);
  a.resize(m);
  return a;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, q;
  cin >> n >> q;
  vector<int> p(n);
  for (auto& x : p) cin >> x, x--;
  vector<int> seen(n);
  map<int, vector<ll>> mp;
  for (int i = 0; i < n; i++) {
    if (seen[i]) continue;
    vector<Z> a;
    for (int cur = i; seen[cur] == 0; cur = p[cur]) {
      a.push_back(cur + 1);
      seen[cur] = 1;
    }
    int sz = (int)a.size();
    auto b = a;
    reverse(a.begin(), a.end());
    a.reserve(2 * sz), b.reserve(2 * sz);
    for (int j = 0; j < sz; j++) a.push_back(0);
    for (int j = 0; j < sz; j++) b.push_back(b[j]);
    auto c = mul(a, b);
    if (mp.count(sz) == 0) mp[sz] = vector<ll>(sz);
    auto& v = mp[sz];
    for (int j = 0; j < sz; j++) v[j] += (ll)c[sz - 1 + j].x;
  }
  while (q--) {
    int k;
    cin >> k;
    ll res = 0;
    for (auto& [sz, v] : mp) res += v[k % sz];
    cout << res << "\n";
  }
}
