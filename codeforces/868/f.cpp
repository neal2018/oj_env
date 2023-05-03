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
  int n, s, t;
  cin >> n >> s >> t, s--, t--;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }

  vector<int> dep(n), path, stk;
  function<void(int, int)> get_dep = [&](int node, int fa) {
    if (fa != -1) {
      dep[node] = dep[fa] + 1;
    }
    stk.push_back(node);
    if (node == s) {
      path = stk;
    }
    for (auto &ne : g[node]) {
      if (ne == fa) continue;
      get_dep(ne, node);
    }
    stk.pop_back();
  };
  get_dep(t, -1);

  vector<int> q = path, nq, dist(n, -1);

  for (int i = 0; i < path.size(); i++) {
    dist[path[i]] = i;
  }

  for (int step = 0; q.size(); swap(q, nq), nq.clear(), step++) {
    for (auto &node : q) {
      for (auto &ne : g[node]) {
        if (dist[ne] == -1) {
          nq.push_back(ne);
          dist[ne] = dist[node];
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (i == t) {
      cout << "1 ";
    } else {
      cout << Z(int(g[i].size())) * dist[i] << " ";
    }
  }
}
