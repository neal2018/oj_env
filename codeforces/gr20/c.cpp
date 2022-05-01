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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector<ll> pos;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == a[i + 1]) {
        pos.push_back(i);
      }
    }
    if (pos.size() == 0) {
      cout << "0\n";
      continue;
    }
    ll res = 1e18;
    for (int i = 0; i < n - 1; i++) {
      ll cur = 0;
      if (pos.back() <= i) {
        cur = i - pos[0];
      } else if (pos[0] < i) {
        cur = i - pos[0] + pos.back() - i - 1;
      } else {
        cur = pos.back() - i;
      }
      // cout << i << " " << cur << "\n";
      // 0, 3
      res = min(res, cur);
    }
    cout << res << "\n";
  }
}
