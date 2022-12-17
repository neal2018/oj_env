#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    array<ll, 26> s{}, t{};
    s[0] = 1, t[0] = 1;
    int maxi_s = 0, maxi_t = 0;
    int q;
    cin >> q;
    while (q--) {
      int d, k;
      string x;
      cin >> d >> k >> x;
      for (auto& c : x) {
        int i = c - 'a';
        (d == 1 ? s : t)[i] += k;
        if (d == 1) {
          maxi_s = max(maxi_s, i);
        } else {
          maxi_t = max(maxi_t, i);
        }
      }
      if (maxi_t > 0) {
        cout << "YES\n";
      } else if (maxi_s == 0 && s[0] < t[0]) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
