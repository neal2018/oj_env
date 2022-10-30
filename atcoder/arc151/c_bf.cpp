#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  map<array<int, 3>, int> memo;
  function<int(int, int, int)> dfs = [&](int n, int s, int e) {
    if (s == 1) s ^= 1, e ^= 1;
    if (memo.count({n, s, e})) return memo[{n, s, e}];
    vector<int> seen(n + 1);
    for (int i = 0; i < n; i++) {
      set<int> poss = {0, 1};
      if (i == 0 && s != -1) {
        poss.erase(s);
      }
      if (i == n - 1 && e != -1) {
        poss.erase(e);
      }
      for (auto& x : poss) {
        auto t = dfs(i, s, x) ^ dfs(n - 1 - i, x, e);
        seen[t] = 1;
      }
    }
    for (int i = 0; i <= n; i++) {
      if (seen[i] == 0) return memo[{n, s, e}] = i;
    }
    throw;
  };
  for (int i = 0; i < 10; i++) {
    cout << dfs(i, 0, 0) << ' ';
  }
}
