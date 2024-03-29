#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 998244353;
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

void ntt(vector<Z> &a, int f) {
  int n = (int)a.size();
  vector<Z> w(n);
  vector<int> rev(n);
  for (int i = 0; i < n; i++) rev[i] = (rev[i / 2] / 2) | ((i & 1) * (n / 2));
  for (int i = 0; i < n; i++)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  Z wn = int(power(ll(f ? (MOD + 1) / 3 : 3), (MOD - 1) / n));
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
    for (int i = 0; i < n; i++) a[i] *= iv;
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
  int n, m;
  cin >> n >> m;
  Comb comb(2 * n);
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  Poly odd, even = {{1}};

  sort(a.begin(), a.end());
  for (int i = 0, j; i < n; i = j) {
    for (j = i; j < n && a[i] == a[j];) j++;
    int sz = j - i;
    Poly t0, t1;
    for (int ii = 0; ii <= sz; ii++) {
      ((ii & 1) ? t1 : t0)[a[i] * ii] += comb.binom(sz, ii);
    }
    auto n_odd = t0 * odd + t1 * even;
    auto n_even = t1 * odd + t0 * even;
    swap(odd, n_odd), swap(even, n_even);
  }
  cout << odd[m] << "\n";
}
