#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  vector<vector<int>> memo(1 << n, vector<int>(n + 1, -1));
  function<int(int, int)> dfs = [&](int mask, int pre) {
    if (mask == 0) return 0;
    int& win = memo[mask][pre];
    if (win != -1) return win;
    win = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        if (pre == n || a[pre].back() == a[i][0]) {
          auto t = dfs(mask ^ (1 << i), i);
          if (!t) {
            win = 1;
            break;
          }
        }
      }
    }
    return win;
  };
  auto res = dfs((1 << n) - 1, n);
  cout << (res ? "First" : "Second") << "\n";
}
