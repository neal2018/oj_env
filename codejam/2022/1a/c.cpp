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
  for (int case_num = 1; case_num <= T; case_num++) {
    cout << "Case #" << case_num << ": ";
    ll n, w;
    cin >> n >> w;
    vector<vector<ll>> a(n);
    for (auto& v : a) {
      for (auto& x : v) cin >> x;
    }
    ll MAX = 4 * 4 * 4 * 4 * 4 * 4 * 4 * 4 * 4 + 1;
    ll inf = 1e18;
    vector<ll> dp(MAX);
    for (int i = 0; i < n; i++) {
      vector<ll> ndp(MAX, inf);
    }
  }
}
