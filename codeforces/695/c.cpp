#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  vector<vector<ll>> a{vector<ll>(n1), vector<ll>(n2), vector<ll>(n3)};
  ll sum = 0;
  vector<ll> mini(3), total(3);
  for (int i = 0; i < 3; i++) {
    for (auto& x : a[i]) cin >> x;
    total[i] = accumulate(a[i].begin(), a[i].end(), 0ll);
    sum += total[i];
    mini[i] = *min_element(a[i].begin(), a[i].end());
  }
  ll res = sum - 2 * *min_element(total.begin(), total.end());
  ll cur = sum - 2 * accumulate(mini.begin(), mini.end(), 0ll);
  cur += 2 * *max_element(mini.begin(), mini.end());
  res = max(res, cur);
  cout << res << "\n";
}
