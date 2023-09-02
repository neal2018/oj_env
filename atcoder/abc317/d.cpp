#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<array<ll, 2>> a;
  ll win = 0, loss = 0;
  for (ll i = 0, x, y, z; i < n; i++) {
    cin >> x >> y >> z;
    if (x > y) {
      win += z;
    } else {
      loss += z;
      a.push_back({(y - x + 1) / 2, z});
    }
  }
  if (win > loss) {
    cout << "0\n";
    return 0;
  }
  ll final_need = (loss - win + 1) / 2;
  vector<ll> dp(win + loss + 1, inf);
  dp[0] = 0;
  for (auto& [need, gain] : a) {
    for (ll i = win + loss; i >= gain; i--) {
      dp[i] = min(dp[i], dp[i - gain] + need);
    }
  }
  auto mini = min_element(dp.begin() + final_need, dp.end());
  cout << *mini << "\n";
}
