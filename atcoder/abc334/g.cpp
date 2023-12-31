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
  vector dfn(n, vector(m, -1)), low(n, vector(m, -1));
  vector e1(n, vector(m, vector<int>{}));

  vector<array<int, 2>> stk;
  int cnt = 0, now = 0;
  function<void(int, int)> tarjan = [&](int x, int y) {
    dfn[x][y] = low[x][y] = now++, stk.push_back({x, y});
    for (auto [dx, dy] : vector<array<int, 2>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
      int xx = x + dx, yy = y + dy;
      if (!(0 <= xx && xx < n && 0 <= yy && yy < m && a[xx][yy] == '#')) {
        continue;
      }
      if (dfn[xx][yy] == -1) {
        tarjan(xx, yy);
        low[x][y] = min(low[x][y], low[xx][yy]);
        if (low[xx][yy] == dfn[x][y]) {
          // e1.push_back({});
          while (true) {
            auto [last_x, last_y] = stk.back();
            stk.pop_back();
            // e1[n + cnt].push_back(x);
            e1[last_x][last_y].push_back(n + cnt);  // undirected
            if (last_x == xx && last_y == yy) break;
          }
          e1[x][y].push_back(n + cnt);
          // e1[n + cnt].push_back(node); // undirected
          cnt++;
        }
      } else {
        low[x][y] = min(low[x][y], dfn[xx][yy]);
      }
    }
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!(dfn[i][j] == -1 && a[i][j] == '#')) continue;
      stk.clear();
      tarjan(i, j);
    }
  }

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

  int green_cnt = 0;
  Z res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != '#') continue;
      green_cnt++;
      res += color_cnt + int(e1[i][j].size()) - 1;
    }
  }
  res /= green_cnt;
  cout << res << "\n";
}
