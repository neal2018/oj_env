#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;
constexpr int inf_int = 1e9;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<array<int, 3>> a(n);
  for (auto& [l, r, c] : a) cin >> l >> r >> c;
  vector<int> dp(n, inf_int);
  // minimal loading time when bullet is full at the end of i
  vector<vector<pair<int, int>>> status(n, vector<pair<int, int>>(n));
  // go through [i, j] with no extra reload
  ll res = inf;
  for (int i = 0; auto& [l, r, c] : a) {
    for (auto j : views::iota(0, i + 1)) {
      // [j, i] start with a full magazine at start of j
      int need = 0, remain = k;
      if (i != j) tie(need, remain) = status[j][i - 1];
      int extra_need = (c - remain + k - 1) / k;
      int cur_remain = remain + extra_need * k - c;
      status[j][i] = {need + extra_need, cur_remain};
      if (extra_need > (r - l) || need == -1) {
        status[j][i] = {-1, -1};
        continue;
      }
      int prev = (j == 0 ? 0 : dp[j - 1]);
      if (prev == inf_int) continue;
      if (i == n - 1) {
        res = min(res, (prev + need + extra_need + 1ll) * k - cur_remain);
      } else {
        if (extra_need < (r - l) || (extra_need == (r - l) && a[i + 1][0] > a[i][1])) {
          dp[i] = min(dp[i], prev + need + extra_need + 1);
        }
      }
    }
    i++;
  }
  cout << (res == inf ? -1 : res) << "\n";
}
