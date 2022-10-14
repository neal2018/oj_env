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
    ll res = 0, pre = 0;
    for (int i = 0; i < n; i++) {
      ll cur = min(a[i], pre + 1);
      res += cur;
      pre = cur;
    }
    cout << res << "\n";
  }
}
