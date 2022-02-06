#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (; T--;) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (auto& [x, y] : a) cin >> x;
    for (auto& [x, y] : a) cin >> y;
    sort(a.begin(), a.end());
    for (auto& [x, y] : a) {
      if (x > k) break;
      k += y;
    }
    cout << k << "\n";
  }
}