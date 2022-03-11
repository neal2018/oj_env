#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  ll inf = 1e9;
  while (T--) {
    ll n, f = 1;
    cin >> n;
    vector<ll> a(n, 1);
    for (int i = 1; i < n; i++) {
      a[i] = a[i - 1] * 3;
      if (a[i] > inf) {
        f = 0;
      }
    }
    if (f == 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (auto& x : a) cout << x << " ";
      cout << "\n";
    }
  }
}
