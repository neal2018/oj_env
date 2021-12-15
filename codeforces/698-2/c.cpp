#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  auto func = [&]() {
    cin >> n;
    vector<ll> d(2 * n);
    for (auto& x : d) cin >> x;
    ranges::sort(d);
    ll sum = 0, cnt = 0, pre = 1e18;
    for (int i = 2 * n - 2; i >= 0; i -= 2, cnt++) {
      if (d[i] != d[i + 1] || d[i] & 1) return false;
      d[i] = d[i] / 2 - sum;
      ll cur = d[i] / (n - cnt);
      if (d[i] % (n - cnt) != 0 || cur <= 0 || pre <= cur) return false;
      pre = cur, sum += pre;
    }
    return true;
  };
  cin >> T;
  while (T--) cout << (func() ? "YES\n" : "NO\n");
}