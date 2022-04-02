#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

ll powerr(ll a, ll b, ll res = 1) {
  for (; b; b /= 2, (a *= a))
    if (b & 1) (res *= a);
  return res;
}

constexpr ll MOD = 3;
ll rrank = 0, llimit = 0;
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
  // auto operator<=>(const Z &) const = default;
  bool operator<(const Z &p) const { return x < p.x; }
  bool operator==(const Z &p) const { return x == p.x; }
  bool operator!=(const Z &p) const { return x != p.x; }
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
  int rank = r - 1;
  for (r = h - 1; r >= 0; r--) {
    for (int c = 0; c < limit; c++) {
      if (!is_0(a[r][c])) {
        T inv_a = 1 / a[r][c];
        for (int i = r - 1; i >= 0; i--) {
          if (is_0(a[i][c])) continue;
          T coeff = -a[i][c] * inv_a;
          for (int j = c; j < w; j++) a[i][j] += coeff * a[r][j];
        }
        break;
      }
    }
  }  // not-free variables: only it on its line
  for (int i = rank + 1; i < h; i++) {
    if (!is_0(a[i][limit])) return 0;
  }
  rrank = rank + 1;
  llimit = limit;
  return (rank + 1 == limit) ? 1 : -1;
}

template <typename T>
pair<int, vector<T>> solve_linear(vector<vector<T>> a, const vector<T> &b, int w) {
  if (a.size() == 0) {
    return {1, vector<T>()};
  }
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
  int S, n;
  cin >> S >> n;
  vector<vector<int>> g(S, vector<int>(S, -1));
  vector<array<int, 3>> aa(n);
  for (auto &tt : aa) {
    int r, c, col;
    cin >> r >> c >> col, r--, c--;
    g[r][c] = col;
    tt = {r, c, col};
  }
  vector<pair<int, int>> unknown;
  map<pair<int, int>, int> p_to_unknown;
  for (int i = 0; i < S; i++) {
    for (int j = 0; j < i + 1; j++) {
      if (g[i][j] == -1) {
        unknown.push_back({i, j});
        p_to_unknown[{i, j}] = int(unknown.size()) - 1;
      }
    }
  }
  int w = (int)unknown.size(), f = 1;
  vector<vector<Z>> a;
  vector<Z> b;
  for (int i = 0; i < S - 1; i++) {
    for (int j = 0; j < i + 1; j++) {
      if (g[i][j] != -1 && g[i + 1][j] != -1 && g[i + 1][j + 1] != -1) {
        Z r = g[i][j] + g[i + 1][j] + g[i + 1][j + 1];
        if (r != 0) {
          cout << "0\n";
          return 0;
        }
      } else {
        Z r = 0;
        vector<Z> t(w);
        vector<pair<int, int>> v = {{i, j}, {i + 1, j}, {i + 1, j + 1}};
        for (auto pp : v) {
          auto x = pp.first, y = pp.second;
          if (g[x][y] == -1) {
            t[p_to_unknown[{x, y}]] = 1;
          } else {
            r -= g[x][y];
          }
        }
        a.push_back(t), b.push_back(r);
      }
    }
  }
  // cout<<a.size()<<"\n";
  auto aaa = solve_linear(a, b, w);
  // cout << aaa.first << " " << rrank << " " << llimit << "\n";
  if (aaa.first == 0) {
    cout << "0\n";
  } else {
    cout << powerr(3, llimit - rrank) << "\n";
  }
}
