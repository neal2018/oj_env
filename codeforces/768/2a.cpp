#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (; T--;) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    for (int i = 0; i < n; i++) {
      auto [mini, maxi] = minmax({a[i], b[i]});
      a[i] = mini, b[i] = maxi;
    }
    int x = *max_element(a.begin(), a.end());
    int y = *max_element(b.begin(), b.end());
    cout << x * y << "\n";
  }
}