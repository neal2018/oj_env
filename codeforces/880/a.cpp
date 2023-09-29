#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    auto get_mini = [&](int t) {
      int res = 1;
      for (int i = 0; i < t - 1; i++) res *= 10;
      return res;
    };
    [&] {
      if (c == max(a, b)) {
        for (int aa = get_mini(a); aa < get_mini(a + 1); aa++) {
          const auto mini_b = get_mini(b);
          const auto maxi_b = min(get_mini(b + 1), get_mini(c + 1) - aa);
          const auto cnt = max(maxi_b - mini_b, 0);
          if (k > cnt) {
            k -= cnt;
          } else {
            const auto bb = mini_b + k - 1;
            cout << aa << " + " << bb << " = " << aa + bb << "\n";
            return;
          }
        }
      } else if (c == max(a, b) + 1) {
        for (int aa = get_mini(a); aa < get_mini(a + 1); aa++) {
          const auto mini_b = max(get_mini(b), get_mini(c) - aa);
          const auto maxi_b = get_mini(b + 1);
          const auto cnt = max(maxi_b - mini_b, 0);
          if (k > cnt) {
            k -= cnt;
          } else {
            const auto bb = mini_b + k - 1;
            cout << aa << " + " << bb << " = " << aa + bb << "\n";
            return;
          }
        }
      }
      cout << "-1\n";
    }();
  }
}
