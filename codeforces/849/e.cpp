#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll dp0 = a[0], dp1 = -1e17;
    for (int i = 1; i < n; i++) {
      ll ndp0 = max(dp0, dp1) + a[i];
      ll ndp1 = max(dp0 - 2 * a[i - 1], dp1 + 2 * a[i - 1]) - a[i];
      dp0 = ndp0, dp1 = ndp1;
    }
    cout << max(dp0, dp1) << "\n";
  }
}
