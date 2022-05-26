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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (auto& [x, y] : a) cin >> x;
    for (auto& [x, y] : a) cin >> y;
    vector<pair<ll, ll>> op;
    for (int i = 0; i < n; i++) {
      int id = i;
      for (int j = i; j < n; j++) {
        if (a[j] < a[id]) {
          id = j;
        }
      }
      if (id != i) {
        op.push_back({id, i});
        swap(a[i], a[id]);
      }
    }
    int f = 1;
    for (int i = 1; i < n; i++) {
      if (a[i - 1].first > a[i].first || a[i - 1].second > a[i].second) {
        f = 0;
      }
    }
    if (!f) {
      cout << "-1\n";
    } else {
      cout << op.size() << "\n";
      for (auto& [x, y] : op) cout << x + 1 << " " << y + 1 << "\n";
    }
  }
}
