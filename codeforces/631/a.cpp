#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll need, n;
  cin >> need >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll maxi = accumulate(a.begin(), a.end(), 0ll), mini = n - 1 + a.back();
  if (need < mini || need > maxi) {
    cout << "-1\n";
    return 0;
  }
  ll extra = need - mini;
  ll pos = 0;
  vector<ll> avail(n);
  for (int i = 0; i < n - 1; i++) {
    avail[i] = a[i] - 1;
  }
  for (ll i = n - 2; i >= 0; i--) avail[i] += avail[i + 1];
  vector<ll> res;
  int f = 1;
  for (int i = 0; i < n; i++) {
    res.push_back(pos);
    if (pos + a[i] > need) f = 0;
    if (i < n - 1 && avail[i + 1] < extra) {
      ll plus = extra - avail[i + 1];
      extra -= plus;
      pos += plus;
    }
    pos += 1;
  }
  if (!f) {
    cout << "-1\n";
  } else {
    for (auto& x : res) cout << x + 1 << " ";
    cout << "\n";
  }
}
