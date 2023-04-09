#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    cout << ([&] {
      for (int i = 0; i < n; i++) {
        if (a[i] <= i + 1) return true;
      }
      return false;
    }()
                 ? "YES\n"
                 : "NO\n");
  }
}
