#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll x, y;
  cin >> x >> y;
  ld len = sqrt(x * x + y * y);
  cout << x / len << " " << y / len << "\n";
}
