#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  auto b = a;
  sort(b.begin(), b.end());
  ll res = (b[0] + 1) / 2 + (b[1] + 1) / 2;
  for (int i = 0; i < n - 1; i++) {
    res = min(res, max({(a[i] + a[i + 1] + 2) / 3, (a[i] + 1) / 2, (a[i + 1] + 1) / 2}));
  }
  for (int i = 1; i < n - 1; i++) {
    res = min(res, max(a[i - 1], a[i + 1]));
    res = min(res, a[i - 1] / 2 + a[i + 1] / 2 + 1);
  }
  cout << res << "\n";
}
