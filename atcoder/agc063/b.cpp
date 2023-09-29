#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<ll> dp(n);
  
  vector<vector<int>> trans(n);
  vector<array<int, 2>> stk;
  for (int i = n - 1; i >= 0; i--) {
    stk.push_back({a[i], i});
    for (int prev = 0; stk.size() && stk.back()[0] == prev + 1; prev++) {
      auto [_, id] = stk.back();
      stk.pop_back();
      dp[id]++;
      if (i > 0) trans[i - 1].push_back(id);
    }
  }
  for (int i = 0; i < n; i++) {
    for (const auto& to : trans[i]) {
      dp[to] += dp[i];
    }
  }
  cout << accumulate(dp.begin(), dp.end(), 0ll) << "\n";
}
