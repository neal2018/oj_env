#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> has(m + 1), cnt(m + 1), dp(m + 1, m);
    int mini = 1e9;
    for (int x; [[maybe_unused]] auto i : views::iota(0, n)) {
      cin >> x, has[x] = 1;
      mini = min(mini, x);
    }
    cnt[m] = accumulate(has.begin(), has.end(), 0);
    int res = m - mini, maxi = m;
    auto update = [&](int pos, int val) {
      if (has[pos]) cnt[dp[pos]]--;
      dp[pos] = val;
      if (has[pos]) cnt[dp[pos]]++;
    };
    for (int i = m; i > 0; i--) {
      update(i, i);
      for (int j = 1; i * j <= m; j++) {
        update(i * j, min(dp[i * j], max(dp[j], i)));
      }
      while (cnt[maxi] == 0) maxi--;
      res = min(res, maxi - min(mini, i));
    }
    cout << res << "\n";
  }
}
