#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll h, n;
    cin >> h >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    a.push_back(0), n++;
    ll res = 0;
    for (int i = 1; i < n - 1; i++) {
      if (a[i] - a[i + 1] > 1) {
        res++;
      } else {
        i++;
      }
    }
    cout << res << "\n";
  };
}
