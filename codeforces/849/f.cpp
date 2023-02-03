#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    set<int> can;
    for (int i = 0; i < n; i++) can.insert(i);
    while (q--) {
      auto update = [](int x) {
        int res = 0;
        while (x) {
          res += x % 10, x /= 10;
        }
        return res;
      };
      int t, l, r;
      cin >> t >> l, l--;
      if (t == 1) {
        cin >> r;
        auto it = can.lower_bound(l);
        while (it != can.end() && *it < r) {
          a[*it] = update(a[*it]);
          if (a[*it] < 10) {
            it = can.erase(it);
          } else {
            it++;
          }
        }
      } else {
        cout << a[l] << "\n";
      }
    }
  }
}
