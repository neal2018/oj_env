#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
constexpr auto eps = 1e-8;
constexpr ll MOD = 998244353;

ll norm(ll x) { return (x + MOD) % MOD; }
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
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2); }
  bool operator < (const Z &rhs) const { return x < rhs.x; }
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
  }
  // for (int i = rank + 1; i < h; i++)
  //   if (!is_0(a[i][limit])) return 0;
  // return (rank == limit) ? 1 : -1;
  return 0;
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
  int n;
  cin >> n;
  vector<vector<string>> left(n), right(n);
  vector<string> all;
  string sin, t, s;
  getline(cin, sin);
  for (int i = 0; i < n; i++) {
    getline(cin, sin);
    stringstream ss(sin);
    // cout << sin << "\n";
    int f = 0;
    while (ss >> s) {
      if (s == "=") {
        f = 1;
      } else if ((s == "*" && !f) || (s == "/" && f)) {
        ss >> t;
        all.push_back(t);
        left[i].push_back(t);
      } else if ((s == "*" && f) || (s == "/" && !f)) {
        ss >> t;
        all.push_back(t);
        right[i].push_back(t);
      } else {
        all.push_back(s);
        (f ? right : left)[i].push_back(s);
      }
    }
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  map<string, int> mp;
  int w = (int)all.size();
  for (int i = 0; i < w; i++) mp[all[i]] = i;
  vector<vector<Z>> a(n, vector<Z>(w + 1));
  for (int i = 0; i < n; i++) {
    auto &xx = a[i];
    for (auto &s : left[i]) {
      xx[mp[s]] += 1;
    }
    for (auto &s : right[i]) {
      xx[mp[s]] -= 1;
    }
  }
  // for (int i = 0; i < n; i++) {
  //   auto &r = a[i];
  //   for (auto &x : r) cout << (x >= -eps ? "+" : "") << x << "\t";
  //   cout << "\n";
  // }
  // cout << "\n";
  // for (int i = 0; i < n; i++) {
  //   cout << "left ";
  //   for (auto &x : left[i]) cout << x << " ";
  //   cout << "\n";
  //   cout << "right ";
  //   for (auto &x : right[i]) cout << x << " ";
  //   cout << "\n";
  // }
  gaussian_elimination(a, w);
  vector<int> count(n);
  // for (int i = 0; i < n; i++) {
  //   auto &r = a[i];
  //   for (auto &x : r) cout << (x >= -eps ? "+" : "") << x << "\t";
  //   cout << "\n";
  // }
  for (int i = 0; i < n; i++) {
    auto &r = a[i];
    int cnt = 0;
    for (auto &x : r)
      if (x.x) cnt++;
    count[i] = cnt;
  }
  int good = 1;
  for (int i = 0; i < n; i++) {
    if (abs(count[i]) == 1 && all[i] != "1") good = 0;
  }
  cout << (good ? "valid\n" : "invalid\n");
}