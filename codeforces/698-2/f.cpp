#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> points(n);
  for (auto& [a, b] : points) cin >> a >> b;
  vector<int> res(n);
  iota(res.begin(), res.end(), 0);
  auto dot = [](ll x1, ll y1, ll x2, ll y2) { return x1 * x2 + y1 * y2; };
  for (int i = 2; i < n; i++) {
    for (int j = i - 2; j >= 0; j -= 1) {
      auto [xa, ya] = points[res[j]];
      auto [xb, yb] = points[res[j + 1]];
      auto [xd, yd] = points[res[j + 2]];
      if (dot(xa - xb, ya - yb, xd - xb, yd - yb) <= 0) {
        swap(res[j + 1], res[j + 2]);
      } else {
        break;
      }
    }
  }
  for (auto& x : res) cout << x + 1 << " ";
  cout << '\n';
}