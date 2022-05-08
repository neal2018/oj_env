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
    ll res = 1, cur = 0, nex = 1;
    for (int i = 2; i < n; i++) {
      if (a[i] < a[i - 1]) {
        if (cur == 0) {
          cur = nex - 1, res++, nex = 0;
        } else {
          cur--;
        }
      }
      nex++;
    }
    cout << res << "\n";
  }
}
