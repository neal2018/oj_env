#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    vector<pair<ll, ll>> a(3);
    for (auto& [y, x] : a) cin >> x >> y;
    sort(a.begin(), a.end());
    if (a[1].first == a[2].first) {
      cout << a[2].second - a[1].second << "\n";
    } else {
      cout << 0 << "\n";
    }
  }
}
