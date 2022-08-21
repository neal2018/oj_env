#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

ll floor_div(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b != 0); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n, m, p, sr, sc;
    cin >> n >> p >> m >> sr >> sc, sr--, sc--;
    auto parse = [&]() -> function<ll(ll)> {
      char c;
      int d;
      cin >> c >> d;
      if (c == '+') return [=](ll x) { return x + d; };
      if (c == '-') return [=](ll x) { return x - d; };
      if (c == '*') return [=](ll x) { return x * d; };
      return [=](ll x) { return floor_div(x, d); };
    };
    vector<pair<pair<int, int>, function<ll(ll)>>> direct(4);
    direct[0] = {{-1, 0}, parse()};
    direct[1] = {{0, 1}, parse()};
    direct[2] = {{0, -1}, parse()};
    direct[3] = {{1, 0}, parse()};

    vector mark(n, vector<int>(n)), gain(n, vector<int>(n));

    for (int i = 0; i < p; i++) {
      int x, y, c;
      cin >> x >> y >> c, x--, y--;
      mark[x][y] = (1 << i), gain[x][y] = c;
    }
    constexpr ll inf = 1e18;
    vector dp(n * n, vector<ll>((1 << p), -inf));
    dp[sr * n + sc][0] = 0;
    for (int _ = 0; _ < m; _++) {
      vector ndp(n * n, vector<ll>((1 << p), -inf));
      for (int i = 0; i < n * n; i++) {
        for (int mask = 0; mask < (1 << p); mask++) {
          if (dp[i][mask] <= -inf) continue;
          int x = i / n, y = i % n;
          ndp[x * n + y][mask] = max(ndp[x * n + y][mask], dp[i][mask]);
          for (auto& [diff, f] : direct) {
            auto [dx, dy] = diff;
            int xx = x + dx, yy = y + dy;
            if (min(xx, yy) < 0 || max(xx, yy) >= n) continue;
            ndp[xx * n + yy][mask] = max(ndp[xx * n + yy][mask], f(dp[i][mask]));
            int n_mask = mask | mark[xx][yy];
            int add = (mask & mark[xx][yy] ? 0 : gain[xx][yy]);
            ndp[xx * n + yy][n_mask] = max(ndp[xx * n + yy][n_mask], f(dp[i][mask]) + add);
          }
        }
      }
      swap(dp, ndp);
    }
    ll res = -inf;
    for (auto& r : dp) res = max(res, r[(1 << p) - 1]);
    if (res <= -inf) {
      cout << "IMPOSSIBLE\n";
    } else {
      cout << res << '\n';
    }
  }
}
