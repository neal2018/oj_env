#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    ll total = n * (n - 1) / 2;
    vector<ll> a(total);
    for (auto& x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    vector<ll> res;
    ll prev = 0;
    for (int i = 0, j = 0; i < total; i = j) {
      for (j = i; j < total && a[i] == a[j];) j++;
      auto get = [&]() {
        ll l = 1, r = n - prev;
        while (l < r) {
          ll t = (l + r) / 2;
          if ((t * prev + t * (t - 1) / 2) < j - i) {
            l = t + 1;
          } else {
            r = t;
          }
        }
        return r;
      }();
      prev += get;
      for (int t = 0; t < get; t++) res.push_back(a[i]);
    }
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}
