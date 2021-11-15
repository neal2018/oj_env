#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MOD = 1e9 + 7;

ll norm(ll x) { return (x + MOD) % MOD; }
template <class T>
T power(T a, ll b) {
  T res = 1;
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}
// #define Z double
struct Z {
  ll x;
  Z(ll _x = 0) : x(norm(_x)) {}
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2); }
  Z &operator*=(const Z &rhs) { return x = x * rhs.x % MOD, *this; }
  Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  Z &operator%=(const auto &_) { return *this; }
  friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  friend Z operator%(Z lhs, const auto &_) { return lhs; }
  friend istream &operator>>(istream &input, Z &z) { return input >> z.x, input; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, q;
  cin >> T;
  // auto solve = [&] {
  // };
  for (ll ttt = 1; ttt <= T; ttt++) {
    ll a1e6 = 1e6;
    cin >> n >> q;
    Z p1[n], p2[n];
    // vector<Z> p1(n), p2(n);
    // vector<int> parent(n, -1), deep(n), hson(n), top(n), sz(n);
    int parent[n], deep[n], hson[n], top[n], sz[n];
    memset(hson, 0, sizeof(hson));
    parent[0] = -1;
    vector<vector<int>> g(n);
    cin >> p1[0];
    p2[0] = 1 - p1[0];
    p1[0] /= a1e6, p2[0] /= a1e6;
    for (int i = 1, p; i < n; i++) {
      cin >> p >> p1[i] >> p2[i];
      p1[i] /= a1e6, p2[i] /= a1e6;
      p--;
      parent[i] = p;
      g[p].push_back(i);
    }
    // lca start
    int root = 0;
    function<int(int, int, int)> dfs = [&](int node, int fa, int dep) {
      deep[node] = dep, sz[node] = 1;
      for (auto &ne : g[node]) {
        if (ne == fa) continue;
        sz[node] += dfs(ne, node, dep + 1);
        if (!hson[node] || sz[ne] > sz[hson[node]]) hson[node] = ne;
      }
      return sz[node];
    };
    function<void(int, int)> dfs2 = [&](int node, int t) {
      top[node] = t;
      if (!hson[node]) return;
      dfs2(hson[node], t);
      for (auto &ne : g[node]) {
        if (ne == parent[node] || ne == hson[node]) continue;
        dfs2(ne, ne);
      }
    };
    dfs(root, -1, 0), dfs2(root, root);
    function<int(int, int)> lca = [&](int x, int y) {
      while (top[x] != top[y]) {
        if (deep[top[x]] < deep[top[y]]) swap(x, y);
        x = parent[top[x]];
      }
      return deep[x] < deep[y] ? x : y;
    };
    // lca end
    Z p_abs[n];  // real
    function<void(int)> dfs3 = [&](int node) {
      if (node == 0) {
        p_abs[node] = p1[0];
      } else {
        p_abs[node] = p1[node] * p_abs[parent[node]] + p2[node] * (1 - p_abs[parent[node]]);
      }
      for (auto &ne : g[node]) dfs3(ne);
    };
    dfs3(0);
    // u, an
    unordered_map<ll, pair<Z, Z>> mp;  // p[u|ans], p[u|!ans]
    mp.reserve(2047);
    auto memo = [&](int t, int an, int save) {
      ll hash = (t << 20) + an;
      if (mp.count(hash)) {
        return mp[hash];
      } else {
        Z pp1 = 1, pp2 = 0;
        int node = t;
        vector<int> pass;
        while (node != an) {
          pass.push_back(node);
          node = parent[node];
        }
        reverse(pass.begin(), pass.end());
        for (int node : pass) {
          pp1 = p1[node] * pp1 + p2[node] * (1 - pp1);
          pp2 = p1[node] * pp2 + p2[node] * (1 - pp2);
        }
        if (save)mp[hash] = pair{pp1, pp2};
        return pair{pp1, pp2};
      }
    };
    auto get = [&](int an, int t) {
      Z pp1 = 1, pp2 = 0;
      int node = t;
      vector<int> pass, pass2;
      while (top[node] != top[an]) {
        pass.push_back(node);
        node = parent[top[node]];
      }
      while (node != an) {
        pass2.push_back(node);
        node = parent[node];
      }
      reverse(pass.begin(), pass.end());
      reverse(pass2.begin(), pass2.end());
      // solve 2
      int cur = an;
      for (int node : pass2) {
        pp1 = p1[node] * pp1 + p2[node] * (1 - pp1);
        pp2 = p1[node] * pp2 + p2[node] * (1 - pp2);
        cur = node;
      }
      // solve 1
      for (int node : pass) {
        auto [m1, m2] = memo(node, cur, node!=pass[0]);
      
        pp1 = m1 * pp1 + m2 * (1 - pp1);
        pp2 = m1 * pp2 + m2 * (1 - pp2);
        cur = node;
      }
      return pair{pp1, pp2};
    };
    cout << "Case #" << ttt << ": ";
    int u, v;
    while (q--) {
      cin >> u >> v;
      u--, v--;
      int com = lca(u, v);
      auto [u_yes, u_no] = get(com, u);
      auto [v_yes, v_no] = get(com, v);
      Z res = p_abs[com] * u_yes * v_yes + (1 - p_abs[com]) * u_no * v_no;
      cout << res.x << ' ';
    }
    cout << '\n';
  }
  return 0;
}