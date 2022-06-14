#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    int good = 0, res = 0;
    for (int i = 1; i < n; i++) {
      if (a[i - 1] < 2 * a[i]) {
        good++;
      } else {
        good = 0;
      }
      if (good >= k) res++;
    }
    cout << res << "\n";
  }
}
