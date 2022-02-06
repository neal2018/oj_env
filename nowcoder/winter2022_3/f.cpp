#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094
constexpr ll MOD = 1e9 + 7;

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

struct Node {
  int l, r;  // [ , )
  array<int, 10> a = {};
  bool operator<(const Node &rhs) const { return l < rhs.l; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, q;
  cin >> n >> m >> q;
  string s;
  cin >> s;
  vector<int> a(n);
  for (auto &x : a) cin >> x, x--;
  vector<set<Node>> v(m);
  for (int i = 0, j; i < n; i = j) {
    for (j = i; j < n && a[i] == a[j];) j++;
    Node node{i, j};
    for (int k = i; k < j; k++) node.a[s[k] - '0']++;
    v[a[i]].insert(node);
  }
  vector<Z> pow10(n + 1, 1), pre(n + 2);
  for (int i = 1; i <= n; i++) pow10[i] = 10 * pow10[i - 1];
  for (int i = 0; i <= n; i++) pre[i + 1] = pre[i] + pow10[i];
  auto get = [&](const Node &node) {
    Z val = 0;
    for (int i = 9; i >= 0; i--) {
      val *= pow10[node.a[i]];
      val += pre[node.a[i]] * i;
    }
    val *= pow10[n - node.r];
    return val;
  };
  Z res = 0;
  for (auto &st : v) {
    for (auto &node : st) res += get(node);
  }
  cout << res << "\n";
  auto merge = [&](set<Node> &from, set<Node> &to) {
    for (auto node : from) {
      res -= get(node);
      while (true) {  // merge latter
        auto it = to.lower_bound(node);
        if (it != to.end() && it->l == node.r) {
          node.r = it->r;
          for (int i = 0; i < 10; i++) node.a[i] += it->a[i];
          res -= get(*it);
          to.erase(it);
        } else {
          break;
        }
      }
      while (true) {  // merge previous
        auto it = to.lower_bound(node);
        if (it != to.begin() && (--it)->r == node.l) {
          node.l = it->l;
          for (int i = 0; i < 10; i++) node.a[i] += it->a[i];
          res -= get(*it);
          to.erase(it);
        } else {
          break;
        }
      }
      res += get(node);
      to.insert(node);
    }
    from.clear();
  };
  while (q--) {
    int pp, qq;
    cin >> pp >> qq, pp--, qq--;
    if (v[pp].size() > v[qq].size()) swap(v[pp], v[qq]);
    if (pp != qq) merge(v[pp], v[qq]);
    cout << res << "\n";
  }
}
