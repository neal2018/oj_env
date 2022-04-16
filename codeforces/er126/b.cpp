#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr int MOD = 32768;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<ll> dp(MOD + 1, -1);
  dp[0] = 0;
  vector<int> q = {0}, nq;
  for (int step = 0; q.size(); swap(q, nq), nq.clear(), step++) {
    for (auto& x : q) {
      // cout << x << "\n";
      if (dp[(x - 1 + MOD) % MOD] == -1) {
        nq.push_back((x - 1 + MOD) % MOD);
        dp[(x - 1 + MOD) % MOD] = step + 1;
      }
      if (x % 2 == 0) {
        if ((x + MOD) / 2 < MOD && dp[(x + MOD) / 2] == -1) {
          nq.push_back((x + MOD) / 2);
          dp[(x + MOD) / 2] = step + 1;
        }
      }
      if (dp[x / 2] == -1) {
        nq.push_back(x / 2);
        dp[x / 2] = step + 1;
      }
    }
  }
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    cout << dp[n] << "\n";
  }
}
