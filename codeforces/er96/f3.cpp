#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<array<ll, 3>> a(n);
  for (auto& [l, r, c] : a) cin >> l >> r >> c;
  vector<ll> need(n);
  for (auto i : views::iota(0, n) | views::reverse) {
    ll cur = a[i][2];
    if (i < n - 1 && a[i + 1][0] == a[i][1]) cur += need[i + 1];
    if ((a[i][1] - a[i][0] + 1) * k < cur) {
      cout << "-1\n";
      return 0;
    }
    need[i] = max(0ll, cur - (a[i][1] - a[i][0]) * k);
  }
  ll res = 0, cur = k;
  for (auto i : views::iota(0, n)) {
    if (cur < need[i]) res += cur, cur = k;
    res += a[i][2], cur = ((cur - a[i][2]) % k + k) % k;
  }
  cout << res << "\n";
}
