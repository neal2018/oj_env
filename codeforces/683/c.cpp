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
  auto func = [&]() {
    ll n, w;
    cin >> n >> w;
    ll half = (w + 1) / 2;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
    sort(a.begin(), a.end());
    while (a.size() && a.back().first > w) {
      a.pop_back();
    }
    n = a.size();
    if (!a.size()) {
      cout << "-1\n";
      return;
    }
    if (a.back().first >= half) {
      cout << "1\n" << a.back().second + 1 << "\n";
      return;
    }
    ll sum = 0;
    for (ll i = n - 1; i >= 0; i--) {
      sum += a[i].first;
      if (sum >= half) {
        cout << n - i << "\n";
        for (ll j = i; j < n; j++) {
          cout << a[j].second + 1 << " ";
        }
        cout << "\n";
        return;
      }
    }
    cout << "-1\n";
  };
  while (T--) {
    func();
  }
}
