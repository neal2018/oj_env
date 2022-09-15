#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 998244353;
template <typename T>
constexpr T power(T a, ll b, int _MOD = MOD, T res = 1) {
  for (; b; b /= 2, (a *= a) %= _MOD)
    if (b & 1) (res *= a) %= _MOD;
  return res;
}
struct Z {
  unsigned int x;
  constexpr Z(int _x = 0) : x(norm(_x)) {}
  static constexpr int norm(int x) {
    if (x < 0) x += MOD;
    if (x >= MOD) x -= MOD;
    return x;
  }
  // auto operator<=>(const Z &) const = default;  // need c++ 20
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

namespace NTT_PRE {
static constexpr int FFT_MAX = 23;
static constexpr Z FFT_RATIOS[FFT_MAX] = {
    911660635U, 509520358U, 369330050U, 332049552U, 983190778U, 123842337U, 238493703U, 975955924U,
    603855026U, 856644456U, 131300601U, 842657263U, 730768835U, 942482514U, 806263778U, 151565301U,
    510815449U, 503497456U, 743006876U, 741047443U, 56250497U,  867605899U};
static constexpr Z INV_FFT_RATIOS[FFT_MAX] = {
    86583718U,  372528824U, 373294451U, 645684063U, 112220581U, 692852209U, 155456985U, 797128860U,
    90816748U,  860285882U, 927414960U, 354738543U, 109331171U, 293255632U, 535113200U, 308540755U,
    121186627U, 608385704U, 438932459U, 359477183U, 824071951U, 103369235U};
};  // namespace NTT_PRE

constexpr int MO = 998244353U;
constexpr int MO2 = 2U * MO;

void invFft(vector<Z> &as) {
  int n = int(as.size());
  int m = 1;
  if (m < n >> 1) {
    Z prod = 1U;
    for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
      for (int i = i0; i < i0 + m; ++i) {
        const long long y = as[i].x + MO - as[i + m].x;  // < 2 MO
        as[i].x += as[i + m].x;                          // < 2 MO
        as[i + m].x = int((prod.x * y) % MO);            // < MO
      }
      prod *= NTT_PRE::INV_FFT_RATIOS[__builtin_ctz(++h)];
    }
    m <<= 1;
  }
  for (; m < n >> 1; m <<= 1) {
    Z prod = 1U;
    for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
      for (int i = i0; i < i0 + (m >> 1); ++i) {
        const long long y = as[i].x + MO2 - as[i + m].x;         // < 4 MO
        as[i].x += as[i + m].x;                                  // < 4 MO
        as[i].x = (as[i].x >= MO2) ? (as[i].x - MO2) : as[i].x;  // < 2 MO
        as[i + m].x = int((prod.x * y) % MO);                    // < MO
      }
      for (int i = i0 + (m >> 1); i < i0 + m; ++i) {
        const long long y = as[i].x + MO - as[i + m].x;  // < 2 MO
        as[i].x += as[i + m].x;                          // < 2 MO
        as[i + m].x = int((prod.x * y) % MO);            // < MO
      }
      prod *= NTT_PRE::INV_FFT_RATIOS[__builtin_ctz(++h)];
    }
  }
  if (m < n) {
    for (int i = 0; i < m; ++i) {
      const int y = as[i].x + MO2 - as[i + m].x;  // < 4 MO
      as[i].x += as[i + m].x;                     // < 4 MO
      as[i + m].x = y;                            // < 4 MO
    }
  }
  const Z invN = Z(n).inv();
  for (int i = 0; i < n; ++i) {
    as[i] *= invN;
  }
}

void ntt(vector<Z> &as, int f) {
  if (f == 1) {
    invFft(as);
    return;
  }
  int n = int(as.size());
  int m = n;
  if (m >>= 1) {
    for (int i = 0; i < m; ++i) {
      const int x = as[i + m].x;       // < MO
      as[i + m].x = as[i].x + MO - x;  // < 2 MO
      as[i].x += x;                    // < 2 MO
    }
  }
  if (m >>= 1) {
    Z prod = 1U;
    for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
      for (int i = i0; i < i0 + m; ++i) {
        const int x = (prod * as[i + m]).x;  // < MO
        as[i + m].x = as[i].x + MO - x;      // < 3 MO
        as[i].x += x;                        // < 3 MO
      }
      prod *= NTT_PRE::FFT_RATIOS[__builtin_ctz(++h)];
    }
  }
  for (; m;) {
    if (m >>= 1) {
      Z prod = 1;
      for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
        for (int i = i0; i < i0 + m; ++i) {
          const int x = (prod * as[i + m]).x;  // < MO
          as[i + m].x = as[i].x + MO - x;      // < 4 MO
          as[i].x += x;                        // < 4 MO
        }
        prod *= NTT_PRE::FFT_RATIOS[__builtin_ctz(++h)];
      }
    }
    if (m >>= 1) {
      Z prod = 1;
      for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
        for (int i = i0; i < i0 + m; ++i) {
          const int x = (prod * as[i + m]).x;                      // < MO
          as[i].x = (as[i].x >= MO2) ? (as[i].x - MO2) : as[i].x;  // < 2 MO
          as[i + m].x = as[i].x + MO - x;                          // < 3 MO
          as[i].x += x;                                            // < 3 MO
        }
        prod *= NTT_PRE::FFT_RATIOS[__builtin_ctz(++h)];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    as[i].x = (as[i].x >= MO2) ? (as[i].x - MO2) : as[i].x;  // < 2 MO
    as[i].x = (as[i].x >= MO) ? (as[i].x - MO) : as[i].x;    // < MO
  }
}

struct Poly {
  vector<Z> a;
  Poly() {}
  Poly(const vector<Z> &_a) : a(_a) {}
  int size() const { return (int)a.size(); }
  void resize(int n) { a.resize(n); }
  Z operator[](int idx) const {
    if (idx < 0 || idx >= size()) return 0;
    return a[idx];
  }
  Z &operator[](int idx) {
    if (idx >= size()) resize(idx + 1);
    return a[idx];
  }
  Poly mulxk(int k) const {
    auto b = a;
    b.insert(b.begin(), k, 0);
    return Poly(b);
  }
  Poly modxk(int k) const { return Poly(vector<Z>(a.begin(), a.begin() + min(k, size()))); }
  Poly divxk(int k) const {
    if (size() <= k) return Poly();
    return Poly(vector<Z>(a.begin() + k, a.end()));
  }
  friend Poly operator+(const Poly &a, const Poly &b) {
    vector<Z> res(max(a.size(), b.size()));
    for (int i = 0; i < (int)res.size(); i++) res[i] = a[i] + b[i];
    return Poly(res);
  }
  friend Poly operator-(const Poly &a, const Poly &b) {
    vector<Z> res(max(a.size(), b.size()));
    for (int i = 0; i < (int)res.size(); i++) res[i] = a[i] - b[i];
    return Poly(res);
  }
  friend Poly operator*(Poly a, Poly b) {
    if (a.size() == 0 || b.size() == 0) return Poly();
    int n = 1, m = (int)a.size() + (int)b.size() - 1;
    while (n < m) n *= 2;
    a.resize(n), b.resize(n);
    ntt(a.a, 0), ntt(b.a, 0);
    for (int i = 0; i < n; i++) a[i] *= b[i];
    ntt(a.a, 1);
    a.resize(m);
    return a;
  }
  friend Poly operator*(Z a, Poly b) {
    for (int i = 0; i < (int)b.size(); i++) b[i] *= a;
    return b;
  }
  friend Poly operator*(Poly a, Z b) {
    for (int i = 0; i < (int)a.size(); i++) a[i] *= b;
    return a;
  }
  Poly &operator+=(Poly b) { return (*this) = (*this) + b; }
  Poly &operator-=(Poly b) { return (*this) = (*this) - b; }
  Poly &operator*=(Poly b) { return (*this) = (*this) * b; }
  Poly deriv() const {
    if (a.empty()) return Poly();
    vector<Z> res(size() - 1);
    for (int i = 0; i < size() - 1; ++i) res[i] = (i + 1) * a[i + 1];
    return Poly(res);
  }
  Poly integr() const {
    vector<Z> res(size() + 1);
    for (int i = 0; i < size(); ++i) res[i + 1] = a[i] / (i + 1);
    return Poly(res);
  }
  Poly inv(int m) const {
    Poly x({a[0].inv()});
    int k = 1;
    while (k < m) {
      k *= 2;
      x = (x * (Poly({2}) - modxk(k) * x)).modxk(k);
    }
    return x.modxk(m);
  }
  Poly log(int m) const { return (deriv() * inv(m)).integr().modxk(m); }
  Poly exp(int m) const {
    Poly x({1});
    int k = 1;
    while (k < m) {
      k *= 2;
      x = (x * (Poly({1}) - x.log(k) + modxk(k))).modxk(k);
    }
    return x.modxk(m);
  }
  Poly _ntt(int f) {
    ntt(a, f);
    return *this;
  }
  Poly pow(int k, int m) const {
    int i = 0;
    while (i < size() && a[i].x == 0) i++;
    if (i == size() || 1LL * i * k >= m) {
      return Poly(vector<Z>(m));
    }
    Z v = a[i];
    auto f = divxk(i) * v.inv();
    return (f.log(m - i * k) * k).exp(m - i * k).mulxk(i * k) * power(v, k);
  }
  Poly sqrt(int m) const {
    Poly x({1});
    int k = 1;
    while (k < m) {
      k *= 2;
      x = (x + (modxk(k) * x.inv(k)).modxk(k)) * ((MOD + 1) / 2);
    }
    return x.modxk(m);
  }
  Poly mulT(Poly b) const {
    if (b.size() == 0) return Poly();
    int n = b.size();
    reverse(b.a.begin(), b.a.end());
    return ((*this) * b).divxk(n - 1);
  }
  Poly divmod(Poly b) const {
    auto n = size(), m = b.size();
    auto t = *this;
    reverse(t.a.begin(), t.a.end());
    reverse(b.a.begin(), b.a.end());
    Poly res = (t * b.inv(n)).modxk(n - m + 1);
    reverse(res.a.begin(), res.a.end());
    return res;
  }
  vector<Z> eval(vector<Z> x) const {
    if (size() == 0) return vector<Z>(x.size(), 0);
    const int n = max(int(x.size()), size());
    vector<Poly> q(4 * n);
    vector<Z> ans(x.size());
    x.resize(n);
    function<void(int, int, int)> build = [&](int p, int l, int r) {
      if (r - l == 1) {
        q[p] = Poly({1, -x[l]});
      } else {
        int m = (l + r) / 2;
        build(2 * p, l, m), build(2 * p + 1, m, r);
        q[p] = q[2 * p] * q[2 * p + 1];
      }
    };
    build(1, 0, n);
    auto work = [&](auto self, int p, int l, int r, const Poly &num) -> void {
      if (r - l == 1) {
        if (l < int(ans.size())) ans[l] = num[0];
      } else {
        int m = (l + r) / 2;
        self(self, 2 * p, l, m, num.mulT(q[2 * p + 1]).modxk(m - l));
        self(self, 2 * p + 1, m, r, num.mulT(q[2 * p]).modxk(r - m));
      }
    };
    work(work, 1, 0, n, mulT(q[1].inv(n)));
    return ans;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // auto t = clock();
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<Z> inv(m + 1, 1);
  for (int i = 2; i <= m; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i];
  Poly plus(vector<Z>(m + 1)), minus(vector<Z>(m + 1));

  sort(a.begin(), a.end());
  for (int i = 0, j; i < n; i = j) {
    for (j = i; j < n && a[i] == a[j];) j++;
    int sz = j - i;
    for (int k = 1; a[i] * k <= m; k++) {
      plus[k * a[i]] += sz * inv[k] * ((k & 1) ? 1 : -1);
      minus[k * a[i]] -= sz * inv[k];
    }
  }
  // cout << (clock() - t) << "\n";
  plus = plus.exp(m + 1);
  minus = minus.exp(m + 1);
  cout << (plus[m] - minus[m]) / 2 << "\n";
  // cout << (clock() - t) << "\n";
}
