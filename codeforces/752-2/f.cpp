#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, d, inf = 1e9, cnt = 0;
  cin >> n >> d;
  vector<tuple<int, int, int>> v;
  for (int i = 0, s, a; i < n; i++) {
    cin >> s >> a;
    if (s < d) continue;
    if (s < a)
      v.push_back({a, s, 0});
    else
      v.push_back({s, a, 1}), cnt++;
  }
  sort(v.begin(), v.end());
  n = v.size();
  int maxi = 0;
  vector<int> dp(n + 1);  // dp[i + 1] for 0..i
  for (int i = 0; i < n; i++) {
    auto [a, s, f] = v[i];
    maxi = max(maxi, s);
    dp[i + 1] = dp[i];
    if (f == 0 && maxi <= s) {
      auto it = upper_bound(v.begin(), v.end(), tuple{s, inf, inf});
      dp[i + 1] = max(dp[i + 1], dp[it - v.begin()] + 1);
    }
  }
  cout << dp.back() + cnt << '\n';
}