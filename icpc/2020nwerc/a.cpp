#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  int MAX = n + 10;
  vector<ll> dp(MAX + 1, inf);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = MAX; j - i >= 0; j--) {
      dp[j] = min(dp[j], dp[j - i] + a[i - 1]);
    }
  }
  int id = 1;
  for (int i = 1; i <= n; i++) {
    if (a[id - 1] * i < a[i - 1] * id) {
      id = i;
    }
  }
  while (q--) {
    ll k;
    cin >> k;
    if (k <= id + 1) {
      cout << dp[k] << "\n";
    } else {
      ll take = (k - (id + 1)) / id;
      ll res = take * id * a[id - 1];
      res += dp[k - take * id];
      cout << res << "\n";
    }
  }
  sort(a.begin(), a.end());
}
