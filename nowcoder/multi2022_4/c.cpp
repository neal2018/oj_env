#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 998244353;
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
  //   auto operator<=>(const Z &) const = default;  // need c++ 20
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

void ntt(vector<Z> &a, int f) {
  int n = (int)a.size();
  vector<int> rev(n);
  for (int i = 0; i < n; i++) rev[i] = (rev[i / 2] / 2) | ((i & 1) * (n / 2));
  for (int i = 0; i < n; i++) {
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  }
  Z wn = power(ll(f ? (MOD + 1) / 3 : 3), (MOD - 1) / n);
  vector<Z> w(n, 1);
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
    Z iv = (1 - MOD) / n;
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
  Z &operator[](int idx) { return a[idx]; }
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

constexpr int MAX = 1e7 + 10;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Comb comb(MAX);
  int n;
  cin >> n;
  vector<int> c(n);
  for (auto &x : c) cin >> x;

  auto mul = [&](vector<Poly> &a, vector<Poly> &b) {
    vector<Poly> res(a.size() + b.size());
    for (int i = 0; i < a.size(); i++) {
      for (int j = 0; j < b.size(); j++) {
        res[i + j] += a[i] * b[j];
      }
    }
    return res;
  };

  vector<Poly> A{Poly{{1}}};
  for (int i = 0; i < n; i++) {
    vector<Poly> X{Poly{{0}}, Poly{{1}}};
    X[0].resize(c[i]);
    for (int t = 0; t < c[i]; t++) {
      X[0][t] -= comb.rf[t];
    }
    A = mul(A, X);
  }

  int q;
  cin >> q;
  while (q--) {
    int N;
    cin >> N;
    Z res = 0;
    for (int i = 0; i < A.size(); i++) {
      Z coef = power((ll)i, N - min(A[i].size() - 1, N));
      for (int j = min(A[i].size() - 1, N); j >= 0; j--) {
        res += A[i][j] * comb.rf[N - j] * coef;
        coef *= i;
      }
    }
    res *= comb.f[N];
    cout << res << "\n";
  }
}
