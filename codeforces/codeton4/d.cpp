#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int q;
    cin >> q;
    ll mini = -1, maxi = -1;
    while (q--) {
      int t;
      cin >> t;
      if (t == 1) {
        ll a, b, n;
        cin >> a >> b >> n;
        ll cur_min = max((a - b) * (n - 1) + 1, n == 1 ? 0 : ((a - b) * (n - 2) + a + 1));
        ll cur_max = (a - b) * (n - 1) + a;
        if (mini == -1) {
          mini = cur_min;
          maxi = cur_max;
          cout << "1 ";
        } else {
          ll n_mini = max(mini, cur_min);
          ll n_maxi = min(maxi, cur_max);
          if (n_mini <= n_maxi) {
            mini = n_mini, maxi = n_maxi;
            cout << "1 ";
          } else {
            cout << "0 ";
          }
        }
      } else {
        ll a, b;
        cin >> a >> b;
        // h > a * (n - 1) - b
        // h <= a * (n - 1) + b + a
        auto get_n = [&](ll h) {
          if (h < a) return 1ll;
          ll n = (h - a - 1) / (a - b);
          ll cur = n * (a - b);
          ll need = h - cur;
          while (need > a) {
            n++, need -= (a - b);
          }
          return n + 1;
        };
        if (mini == -1) {
          cout << "-1 ";
          continue;
        }
        auto mini_n = get_n(mini);
        auto maxi_n = get_n(maxi);
        if (mini_n == maxi_n) {
          cout << mini_n << " ";
        } else {
          cout << "-1 ";
        }
      }
    }
    cout << "\n";
  }
}
