#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  constexpr int N = 29, SIZE = 2;
  vector<vector<int>> trie = {vector<int>(SIZE)};
  vector<int> go = {0};
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  for (auto x : a) {
    int node = 0;
    for (int t = N; t >= 0; t--) {
      int i = (x >> t) & 1;
      if (trie[node][i] == 0) {
        trie.push_back(vector<int>(SIZE)), go.push_back(0);
        trie[node][i] = (int)trie.size() - 1;
      }
      node = trie[node][i], go[node]++;
    }
  }
  function<Z(ll, ll, ll)> solve = [&](ll u, ll v, ll d) {
    if ((d != N && (!u || !v)) || d < 0) return power(Z(2), go[u] + (u == v ? 0 : go[v]));
    if ((k >> d) & 1) {
      if (u == v) {
        return solve(trie[u][0], trie[u][1], d - 1);
      } else {
        return solve(trie[u][0], trie[v][1], d - 1) * solve(trie[u][1], trie[v][0], d - 1);
      }
    } else {
      Z add = solve(trie[u][0], trie[v][0], d - 1) + solve(trie[u][1], trie[v][1], d - 1) - 1;
      if (u == v) {
        return add;
      } else {
        Z uu = (power(Z(2), go[trie[u][0]]) - 1) * (power(Z(2), go[trie[u][1]]) - 1);
        Z vv = (power(Z(2), go[trie[v][0]]) - 1) * (power(Z(2), go[trie[v][1]]) - 1);
        return uu + vv + add;
      }
    }
  };
  cout << solve(0, 0, N) - 1 << "\n";
}
