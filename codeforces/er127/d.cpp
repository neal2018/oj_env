#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector<ll> low(n + 1), high(n + 1);
    low[0] = abs(a[0] - 1), low[n] = abs(a[n - 1] - 1);
    high[0] = abs(a[0] - m), high[n] = abs(a[n - 1] - m);
    ll origin = 0;
    for (int i = 1; i < n; i++) {
      origin += abs(a[i - 1] - a[i]);
      low[i] = abs(a[i] - 1) + abs(a[i - 1] - 1) - abs(a[i - 1] - a[i]);
      high[i] = abs(a[i] - m) + abs(a[i - 1] - m) - abs(a[i - 1] - a[i]);
    }
    multiset<ll> low_st(low.begin(), low.end()), high_st(high.begin(), high.end());
    ll res = 1e18;
    for (int i = 0; i <= n; i++) {
      auto h = *high_st.begin();
      if (h == high[i]) {
        h = *(++high_st.begin());
      }
      ll left = (i == 0 ? abs(1 - m) : (abs(1 - m) + abs(a[i - 1] - m) - abs(a[i - 1] - 1)));
      ll right = (i == n ? abs(1 - m) : (abs(1 - m) + abs(a[i] - m) - abs(a[i] - 1)));
      res = min(res, low[i] + min({h, left, right}));
    }
    cout << res + origin << "\n";
  }
}
