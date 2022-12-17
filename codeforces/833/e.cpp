#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;
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

struct CartesianTree {
  int n;
  vector<int> lson, rson;
  CartesianTree(const vector<int> &a) : n(int(a.size())), lson(n, -1), rson(n, -1) {
    vector<int> stk;
    for (int i = 0; i < n; i++) {
      while (stk.size() && a[stk.back()] < a[i]) {
        lson[i] = stk.back(), stk.pop_back();
      }
      if (stk.size()) rson[stk.back()] = i;
      stk.push_back(i);
    }
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int root = int(max_element(a.begin(), a.end()) - a.begin());
    auto tree = CartesianTree(a);
    vector dp(n, vector<Z>(m));
    vector seen(n, 0);
    function<void(int)> dfs = [&](int node) {
      for (auto ne : {tree.lson[node], tree.rson[node]}) {
        if (ne != -1) dfs(ne);
      }
      Z left = tree.lson[node] == -1, right = tree.rson[node] == -1;
      for (int i = 0; i < m; i++) {
        if (i > 0 && tree.lson[node] != -1) left += dp[tree.lson[node]][i - 1];
        if (tree.rson[node] != -1) right += dp[tree.rson[node]][i];
        dp[node][i] = left * right;
      }
    };
    dfs(root);
    Z res = accumulate(dp[root].begin(), dp[root].end(), Z(0));
    cout << res << "\n";
  }
}
