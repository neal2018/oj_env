#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  ll res = 0;
  array<map<int, vector<int>>, 2> mp;
  for (int i = 0; i < n; i++) {
    mp[i % 2][a[i]].push_back(i);
  }
  int radius = k / 2;
  for (int i = 0; i < n; i++) {
    // radius <= k <= n - 1 - radius
    // i + 1 <= k <= radius + i
    int left = 2 * max(radius, i + 1) - i;
    int right = 2 * min(n - 1 - radius, radius + i) - i;
    if (right < left) break;
    const auto& v = mp[i % 2][a[i]];
    auto left_it = lower_bound(v.begin(), v.end(), left);
    auto right_it = upper_bound(v.begin(), v.end(), right);
    int same_cnt = int(right_it - left_it);
    res += (right - left + 2) / 2 - same_cnt;
  }
  cout << res << "\n";
}
