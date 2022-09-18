#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Rational {
  ll x, y;
  void norm() {
    if (x == 0) y = 1;
    auto g = gcd(x, y);
    x /= g, y /= g;
    if (y < 0) x = -x, y = -y;
  }
  Rational(ll _x, ll _y) : x(_x), y(_y) { norm(); }
  Rational(ll _x) : x(_x), y(1) { norm(); }
};

Rational operator+(Rational lhs, const Rational &rhs) {
  auto x = lhs.x * rhs.y + rhs.x * lhs.y;
  auto y = lhs.y * rhs.y;
  return Rational(x, y);
}
Rational operator-(Rational lhs, const Rational &rhs) {
  auto x = lhs.x * rhs.y - rhs.x * lhs.y;
  auto y = lhs.y * rhs.y;
  return Rational(x, y);
}
Rational operator*(Rational lhs, const Rational &rhs) {
  auto x = lhs.x * rhs.x;
  auto y = lhs.y * rhs.y;
  return Rational(x, y);
}
Rational operator/(Rational lhs, const Rational &rhs) {
  auto x = lhs.x * rhs.y;
  auto y = lhs.y * rhs.x;
  return Rational(x, y);
}
bool operator<(Rational lhs, const Rational &rhs) { return (lhs - rhs).x < 0; }
bool operator==(Rational lhs, const Rational &rhs) { return (lhs - rhs).x == 0; }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  Rational res(*min_element(a.begin(), a.end()));
  vector<int> ones(n);
  function<int(int, int)> dfs = [&](int node, int fa) {
    vector<int> one;
    for (auto &ne : g[node]) {
      if (ne == fa) continue;
      auto o = dfs(ne, node);
      one.push_back(o);
    }
    sort(one.begin(), one.end(), greater());
    if (a[node] != 1) {
      return ones[node] = 0;
    } else {
      return ones[node] = 1 + (one.size() ? one[0] : 0);
    }
  };

  dfs(0, -1);
  function<void(int, int, int)> dfs2 = [&](int node, int fa, int above) {
    vector<int> one;
    for (auto &ne : g[node]) {
      if (ne == fa) continue;
      one.push_back(ones[ne]);
    }
    one.push_back(above);
    sort(one.begin(), one.end(), greater());
    int t = 0;
    if (one.size() > 0) t += one[0];
    if (one.size() > 1) t += one[1];
    auto c = Rational(a[node], t + 1);
    if (c < res) res = c;

    one.push_back(0);
    sort(one.begin(), one.end(), greater());
    for (auto &ne : g[node]) {
      if (ne == fa) continue;
      if (a[node] != 1) {
        dfs2(ne, node, 0);
      } else {
        int bonus = 1 + (ones[ne] == one[0] ? one[1] : one[0]);
        dfs2(ne, node, bonus);
      }
    }
  };
  dfs2(0, -1, 0);
  cout << res.x << "/" << res.y << "\n";
}
