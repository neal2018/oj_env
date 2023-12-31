#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 998244353;
int power(int, ll) = delete;
template <typename T>
T power(T a, ll b, int _MOD = MOD, T res = 1) {
  for (; b; b /= 2, (a *= a) %= _MOD)
    if (b & 1) (res *= a) %= _MOD;
  return res;
}
struct Z {
  int x;
  Z(int _x = 0) : x(norm(_x)) {}
  Z(long long _x) : x(norm(int((_x % MOD + MOD) % MOD))) {}
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto &x : a) cin >> x;
  vector color(n, vector<int>(m, -1));
  int color_cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!(color[i][j] == -1 && a[i][j] == '#')) continue;
      function<void(int, int)> dfs = [&](int x, int y) {
        color[x][y] = color_cnt;
        for (auto [dx, dy] : vector<array<int, 2>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
          int xx = x + dx, yy = y + dy;
          if (!(0 <= xx && xx < n && 0 <= yy && yy < m && color[xx][yy] == -1 &&
                a[xx][yy] == '#')) {
            continue;
          }
          dfs(xx, yy);
        }
      };
      dfs(i, j);
      color_cnt++;
    }
  }
  Z res = 0;
  int red_cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '#') continue;
      set<int> connected;
      for (auto [dx, dy] : vector<array<int, 2>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
        int xx = i + dx, yy = j + dy;
        if (!(0 <= xx && xx < n && 0 <= yy && yy < m && a[xx][yy] == '#')) {
          continue;
        }
        connected.insert(color[xx][yy]);
      }
      res += color_cnt - int(connected.size()) + 1;
      red_cnt++;
    }
  }
  res /= red_cnt;
  cout << res << "\n";
}
