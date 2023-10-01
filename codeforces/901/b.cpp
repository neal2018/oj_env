#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c, d, m;
    cin >> a >> b >> c >> d >> m;
    map<array<int, 2>, int> mp;
    function<int(int, int)> dfs = [&](int x, int y) {
      if (mp.count({x, y})) return mp[{x, y}];
      if (x == c && y == d) return 0;
      mp[{x, y}] = inf;
      auto res = 1 + min({dfs(x & y, y), dfs(x | y, y), dfs(x, x ^ y), dfs(x, m ^ y)});
      if (res > inf) res = inf;
      return mp[{x, y}] = res;
    };
    auto t = dfs(a, b);
    if (t == inf) {
      throw;
      cout << "-1\n";
    } else {
      cout << t << "\n";
    }
  }
}
