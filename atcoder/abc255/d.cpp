#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  vector<ll> pre(n + 1);
  for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
  while (q--) {
    int x;
    cin >> x;
    auto pos = lower_bound(a.begin(), a.end(), x) - a.begin();
    // \sum (x - small) + \sum (large - x)
    ll res = (pos)*x - pre[pos] + (pre[n] - pre[pos]) - (n - pos) * x;
    cout << res << "\n";
  }
}
