#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), pre(n + 1);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end(), greater<ll>());
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
    while (q--) {
      ll x;
      cin >> x;
      auto it = lower_bound(pre.begin(), pre.end(), x);
      if (it == pre.end()) {
        cout << "-1\n";
      } else {
        cout << it - pre.begin() << "\n";
      }
    }
  }
}
