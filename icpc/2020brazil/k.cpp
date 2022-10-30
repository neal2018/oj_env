#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 2;
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

bool is_0(Z v) { return v.x == 0; }
Z abs(Z v) { return v; }
bool is_0(double v) { return abs(v) < 1e-9; }

// 1 => unique solution, 0 => no solution, -1 => multiple solutions
template <typename T>
int gaussian_elimination(vector<vector<T>> &a, int limit) {
  if (a.empty() || a[0].empty()) return -1;
  int h = (int)a.size(), w = (int)a[0].size(), r = 0;
  for (int c = 0; c < limit; c++) {
    int id = -1;
    for (int i = r; i < h; i++) {
      if (!is_0(a[i][c]) && (id == -1 || abs(a[id][c]) < abs(a[i][c]))) {
        id = i;
      }
    }
    if (id == -1) continue;
    if (id > r) {
      swap(a[r], a[id]);
      for (int j = c; j < w; j++) a[id][j] = -a[id][j];
    }
    vector<int> nonzero;
    for (int j = c; j < w; j++) {
      if (!is_0(a[r][j])) nonzero.push_back(j);
    }
    T inv_a = 1 / a[r][c];
    for (int i = r + 1; i < h; i++) {
      if (is_0(a[i][c])) continue;
      T coeff = -a[i][c] * inv_a;
      for (int j : nonzero) a[i][j] += coeff * a[r][j];
    }
    ++r;
  }
  for (int row = h - 1; row >= 0; row--) {
    for (int c = 0; c < limit; c++) {
      if (!is_0(a[row][c])) {
        T inv_a = 1 / a[row][c];
        for (int i = row - 1; i >= 0; i--) {
          if (is_0(a[i][c])) continue;
          T coeff = -a[i][c] * inv_a;
          for (int j = c; j < w; j++) a[i][j] += coeff * a[row][j];
        }
        break;
      }
    }
  }  // not-free variables: only it on its line
  for (int i = r; i < h; i++)
    if (!is_0(a[i][limit])) return 0;
  return (r == limit) ? 1 : -1;
}

template <typename T>
pair<int, vector<T>> solve_linear(vector<vector<T>> a, const vector<T> &b, int w) {
  int h = (int)a.size();
  for (int i = 0; i < h; i++) a[i].push_back(b[i]);
  int sol = gaussian_elimination(a, w);
  if (!sol) return {0, vector<T>()};
  vector<T> x(w, 0);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (!is_0(a[i][j])) {
        x[j] = a[i][w] / a[i][j];
        break;
      }
    }
  }
  return {sol, x};
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> deg(n);
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
    deg[u]++, deg[v]++;
  }
  vector<vector<Z>> a(n, vector<Z>(n + 1));
  for (int i = 0; i < n; i++) {
    if (deg[i] % 2 == 0) {
      a[i].back() = 1;
      for (auto &ne : g[i]) {
        a[i][ne] = 1;
      }
    } else {
      a[i][i] = 1;
      for (auto &ne : g[i]) {
        a[i][ne] = 1;
      }
    }
  }
  auto t = gaussian_elimination(a, n);
  if (t) {
    cout << "Y\n";
  } else {
    cout << "N\n";
  }
}
