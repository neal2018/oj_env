#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define LOCAL

int main() {
#ifdef LOCAL
  ifstream cin("/Users/neallai/Projects/oj_env/input.txt");
  ofstream cout("/Users/neallai/Projects/oj_env/output.txt");
#endif  // LOCAL
  ll T, n, k, x;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<vector<ll>> cave(n);
    vector<ll> mini(n);
    for (ll i = 0; i < n; i++) {
      cin >> k;
      for (ll j = 0; j < k; j++) {
        cin >> x;
        cave[i].push_back(x);
        mini[i] = max(mini[i], x - j);
      }
    }
    vector<ll> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](ll a, ll b) { return mini[a] < mini[b]; });
    // for (auto& x : mini) cout << x << " ";
    // cout << endl;
    // for (auto& x : order) cout << x << " ";
    // cout << endl;
    auto check = [&](ll p) {
      for (int i = 0; i < n; i++) {
        auto& c = cave[order[i]];
        for (auto& m : c) {
          // cout << "m=" << m << " p=" << p << endl;
          if (p > m) {
            p++;
          } else {
            return false;
          }
        }
      }
      return true;
    };
    // cout<<check(14);
    ll l = 2, r = 10e9 + 1;
    while (l < r) {
      ll mid = (l + r) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << l << endl;
  }
}
