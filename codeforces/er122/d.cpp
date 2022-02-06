#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll MAX_N = 1e3 + 10;

int main() {
  vector<int> a(MAX_N, 1e9);
  a[1] = 0;
  for (int i = 1; i < MAX_N; i++) {
    for (int j = 1; j < MAX_N; j++) {
      ll nex = i + i / j;
      if (nex < MAX_N) a[nex] = min(a[nex], a[i] + 1);
    }
  }
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> b(n), c(n);
    for (auto& x : b) cin >> x;
    for (auto& x : c) cin >> x;
    k = min(k, 12 * n);
    vector<ll> dp(k + 1);
    for (int i = 0; i < n; i++) {
      ll w = a[b[i]];
      for (ll j = k - w; j >= 0; j--) {
        dp[j + w] = max(dp[j + w], dp[j] + c[i]);
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
  }
}