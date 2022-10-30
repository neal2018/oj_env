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
    vector<ll> p(n), pos(n);
    for (int i = 0; auto& x : p) cin >> x, pos[x] = i++;
    ll mini = n, maxi = 0;
    ll res = 0;
    ll cur = 1;
    for (int i = 0; i < n; i++) {
      mini = min(mini, pos[i]);
      maxi = max(maxi, pos[i]);
      while (cur <= 2 * (i + 1)) {
        if (cur >= maxi - mini + 1) {
          auto gain = min({cur - (maxi - mini + 1) + 1, n - cur + 1, mini + 1, n - 1 - maxi + 1});
          res += max(0ll, gain);
        }
        cur++;
      }
    }
    cout << res << "\n";
  }
}
