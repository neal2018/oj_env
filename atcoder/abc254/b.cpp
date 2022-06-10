#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<vector<ll>> a(n, {1});
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < i; j++) {
      a[i].push_back(a[i - 1][j - 1] + a[i - 1][j]);
    }
    a[i].push_back(1);
  }
  for (auto& r : a) {
    for (auto& x : r) cout << x << " ";
    cout << "\n";
  }
}
