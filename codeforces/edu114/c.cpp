#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n, m, x, y, res, sum = 0;
  cin >> n;
  vector<ll> a(n);
  for (auto& xx : a) {
    cin >> xx;
    sum += xx;
  }
  sort(a.begin(), a.end());
  cin >> m;
  for (ll i = 0; i < m; i++) {
    cin >> x >> y;
    res = 2 * 1e18;
    auto t = lower_bound(a.begin(), a.end(), x);
    if (t != a.end()) {
      res = min(res, max(0ll, y - (sum - *t)));
    }
    if (t != a.begin()) {
      t--;
      res = min(res, max(0ll, y - (sum - *t)) + max(0ll, x - *t));
    }
    cout << res << '\n';
  }
}