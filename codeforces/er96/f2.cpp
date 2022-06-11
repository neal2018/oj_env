#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;
constexpr int inf_int = 1e9;

main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<array<int, 3>> a(n);
  for (auto& [l, r, c] : a) cin >> l >> r >> c;
  vector<int> dp(n, inf_int);
  // minimal loading time when bullet is full at the end
  // of wave i
  vector<int> dp_extra(n, inf_int);  // one more second
  vector<vector<pair<int, int>>> status(n, vector<pair<int, int>>(n));
  // go through [i, j] with no extra reload
  ll res = inf;
  for (int i = 0; auto& [l, r, c] : a) {
    for (auto j : views::iota(0, i + 1)) {
      // [j, i] start with a full magazine at start of j
      int prev = (j == 0 ? 0 : dp[j - 1]);
      int need = 0, remain = k;
      if (i != j) tie(need, remain) = status[j][i - 1];
      int extra_need = (c - remain + k - 1) / k;
      int cur_remain = remain + extra_need * k - c;
      status[j][i] = {need + extra_need, cur_remain};
      if (extra_need > (r - l) || need == -1) {
        status[j][i] = {-1, -1};
        continue;
      }
      if (j != 0) {
        if (a[j][0] > a[j - 1][1] && dp_extra[j - 1] != inf_int) {
          prev = min(dp[j - 1], dp_extra[j - 1]);
        }
      }
      if (prev == inf_int) continue;
      if (i == n - 1) {
        // cout << "j=" << j << " need=" << need << " remain=" << cur_remain << " prev=" << prev
        //      << " extra_need=" << extra_need << "\n";
        // cout << (need + extra_need + prev + 1ll) * k - cur_remain << "\n";
        res = min(res, (prev + need + extra_need + 1ll) * k - cur_remain);
      } else {
        if (extra_need < (r - l)) {
          dp[i] = min(dp[i], prev + need + extra_need + 1);
        } else if (extra_need == (r - l)) {
          dp_extra[i] = min(dp_extra[i], prev + need + extra_need + 1);
        }
      }
    }
    i++;
  }
  cout << (res == inf ? -1 : res) << "\n";
}
