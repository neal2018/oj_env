#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 998244353;

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

constexpr int MAX_N = 200;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  vector<Z> f(MAX_N, 1), rf(MAX_N, 1);
  for (int i = 2; i < MAX_N; i++) f[i] = f[i - 1] * i % MOD;
  rf[MAX_N - 1] = power(f[MAX_N - 1], MOD - 2);
  for (int i = MAX_N - 2; i > 1; i--) rf[i] = rf[i + 1] * (i + 1) % MOD;

  int n;
  cin >> n;
  vector<pair<int, int>> points(n);
  for (auto &[x, y] : points) cin >> x >> y;
  auto get_dist = [&](int i, int j) {
    return abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second);
  };
  vector<array<int, 3>> edges;
  for (auto i : views::iota(0, n)) {
    for (auto j : views::iota(i + 1, n)) edges.push_back({get_dist(i, j), i, j});
  }
  sort(edges.begin(), edges.end());
  vector<int> cnt, marked(n);
  for (int i = 0, j; i < edges.size(); i = j) {
    for (j = i; j < edges.size() && edges[i][0] == edges[j][0];) j++;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    function<int(int)> find = [&](int x) { return x == p[x] ? x : (p[x] = find(p[x])); };
    auto merge = [&](int x, int y) { p[find(x)] = find(y); };

    for (int k = i; k < j; k++) merge(edges[k][1], edges[k][2]);
    vector<vector<int>> group(n);
    for (auto k : views::iota(0, n)) group[find(k)].push_back(k);
    for (auto &v : group) {
      if (int sz = int(v.size()); sz > 1) {
        [&] {
          for (auto &x : v) {
            if (marked[x]) return;
          }
          for (auto ii : views::iota(0, sz)) {
            for (auto jj : views::iota(ii + 1, sz)) {
              if (get_dist(v[ii], v[jj]) != edges[i][0]) return;
            }
          }
          cnt.push_back(sz);
        }();
        for (auto &x : v) marked[x] = 1;
      }
    }
  }
  for (int t = accumulate(cnt.begin(), cnt.end(), 0); t < n; t++) cnt.push_back(1);
  int sz = int(cnt.size());
  vector dp(sz + 1, vector<Z>(n + 1));
  dp[0][0] = 1;
  for (auto i : views::iota(1, sz + 1)) {
    for (auto j : views::iota(1, n + 1)) {
      dp[i][j] = dp[i - 1][j - 1];
      if (cnt[i - 1] <= j && cnt[i - 1] > 1) dp[i][j] += dp[i - 1][j - cnt[i - 1]];
    }
  }
  Z res = 0;
  for (auto j : views::iota(1, n + 1)) res += dp[sz][j] * f[n] * rf[n - j];
  cout << res << "\n";
}
