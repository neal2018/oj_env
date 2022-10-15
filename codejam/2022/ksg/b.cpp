#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    ll rs, rh;
    cin >> rs >> rh;
    int n;
    cin >> n;
    vector<pair<ll, ll>> a;
    for (int i = 0; i < n; i++) {
      ll x, y;
      cin >> x >> y;
      ll dist = x * x + y * y, t = 0;
      a.push_back({dist, t});
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      ll x, y;
      cin >> x >> y;
      ll dist = x * x + y * y, t = 1;
      a.push_back({dist, t});
    }
    sort(a.begin(), a.end());
    int res = 0;
    for (int i = 0; i < n + m; i++) {
      if ((a[i].second != a[0].second) || (a[i].first > (rs + rh) * (rs + rh))) {
        break;
      }
      res++;
    }
    if (n + m == 0 || a[0].second == 0) {
      cout << res << " 0\n";
    } else {
      cout << "0 " << res << "\n";
    }
  }
}
