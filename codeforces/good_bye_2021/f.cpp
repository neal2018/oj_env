#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 3;

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

bool is_0(Z v) { return v.x == 0; }
Z abs(Z v) { return v; }
bool is_0(double v) { return abs(v) < 1e-9; }

template <typename T>
void gaussian_elimination(vector<vector<T>> &a, int limit) {
  if (a.empty() || a[0].empty()) return;
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
      for (auto j : nonzero) a[i][j] += coeff * a[r][j];
    }
    ++r;
  }
  // check r and w for non/multi/only solution
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
  }
}

template <typename T>
vector<T> solve_linear(vector<vector<T>> a, const vector<T> &b, int w) {
  int h = (int)a.size();
  for (int i = 0; i < h; i++) a[i].push_back(b[i]);
  gaussian_elimination(a, w);
  vector<T> x(w, 0);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (!is_0(a[i][j])) {
        x[j] = a[i][w] / a[i][j];
        break;
      }
    }
  }
  return x;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> unknown, edges(m), e_to_unknown(m, -1);
    vector g(n, vector<int>(n, -1));
    for (int i = 0, a, b; i < m; i++) {
      cin >> a >> b >> edges[i], a--, b--, edges[i]--;
      g[a][b] = i, g[b][a] = i;
      if (edges[i] == -2) {
        e_to_unknown[i] = (int)unknown.size();
        unknown.push_back(i);
      }
    }
    auto check_tri = [&](int a, int b, int c) {
      if (g[a][b] == -1) return 0;
      if (g[b][c] == -1) return 0;
      if (g[c][a] == -1) return 0;
      return 1;
    };
    vector<vector<Z>> a;
    vector<Z> b;
    int w = (int)unknown.size(), f = 1;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (check_tri(i, j, k)) {
            vector<Z> t(w);
            Z r = 0;
            int has = 0;
            for (auto x : {g[i][j], g[j][k], g[k][i]}) {
              if (edges[x] == -2) {
                t[e_to_unknown[x]] = 1, has = 1;
              } else {
                r -= edges[x];
              }
            }
            if (!has && r != 0) f = 0;
            if (has) a.push_back(t), b.push_back(r);
          }
        }
      }
    }
    if (f) {
      auto res = solve_linear(a, b, w);
      for (int i = 0; i < a.size(); i++) {
        Z temp = 0;
        for (int j = 0; j < w; j++) temp += res[j] * a[i][j];
        if (temp != b[i]) f = 0;
      }
      if (f) {
        for (int i = 0; i < m; i++) {
          if (edges[i] == -2) {
            cout << res[e_to_unknown[i]].x + 1 << " ";
          } else {
            cout << edges[i] + 1 << " ";
          }
        }
        cout << "\n";
        continue;
      }
    }
    cout << -1 << "\n";
  }
}