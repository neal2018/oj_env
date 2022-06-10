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
    ll cur = n;
    vector<pair<ll, ll>> res;
    for (ll i = n - 1; i >= 1; i--) {
      res.push_back({cur, i});
      cur = (cur + i + 1) / 2;
    }
    cout << cur << "\n";
    for (auto& [x, y] : res) cout << x << " " << y << "\n";
  }
}
