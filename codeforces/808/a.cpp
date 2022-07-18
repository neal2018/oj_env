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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    if (q > n) {
      cout << string(n, '1') << "\n";
      continue;
    }
    string res;
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    auto check = [&](ll mid) {
      auto b = a;
      for (auto& x : b) {
        if (x > q) x = q + 1;
      }
      sort(id.begin(), id.end(), [&](int x, int y) {
        if (b[x] != b[y]) return b[x] < b[y];
        if (b[x] > q) return x > y;
        return x < y;
      });
      string pos(n, '0');
      for (int i = 0; i < mid; i++) {
        pos[id[i]] = '1';
      }
      int t = q;
      for (int i = 0; i < n; i++) {
        if (pos[i] == '1') {
          if (t == 0) return false;
          if (a[i] > t) {
            t--;
          }
        }
      }
      res = pos;
      return true;
    };
    ll l = 0, r = n;
    while (l < r) {
      ll mid = (l + r + 1) / 2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    // check(2);
    auto bf = [&] {
      int maxi = 0;
      for (int mask = (1 << n) - 1; mask >= 0; mask--) {
        if ([&] {
              int t = q;
              for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                  if (t == 0) return false;
                  if (a[i] > t) {
                    t--;
                  }
                }
              }
              return true;
            }()) {
          maxi = max(maxi, __builtin_popcount(mask));
        }
      }
      return maxi;
    };
    cout << res << '\n';
    // auto t = bf();
    // assert(l == t);
  }
}
