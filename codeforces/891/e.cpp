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
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector<ll> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](auto i, auto j) { return a[i] < a[j]; });
    ll cur = 0;
    for (auto& i : order) {
      cur += a[i] - a[order[0]] + 1;
    }
    vector<ll> res(n);
    for (int ii = 0; ii < n; ii++) {
      auto i = order[ii];
      res[i] = cur;
      if (ii < n - 1) {
        const auto nex_i = order[ii + 1];
        const auto diff = a[nex_i] - a[i];
        cur -= (n - ii - 1) * diff;
        cur += (ii + 1) * diff;
      }
    }
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}
