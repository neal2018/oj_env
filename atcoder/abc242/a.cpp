#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);
  ll a, b, c, x;
  cin >> a >> b >> c >> x;
  if (x <= a) {
    cout << 1 << "\n";
  } else if (x <= b) {
    cout << (long double)c / (b - a) << "\n";
  } else {
    cout << 0 << "\n";
  }
}
