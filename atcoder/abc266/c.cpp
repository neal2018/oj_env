#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

auto dot(complex<int>& x, complex<int>& y) { return (conj(x) * y).real(); }
auto cross(complex<int>& x, complex<int>& y) { return (conj(x) * y).imag(); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  vector<complex<int>> a(4);
  for (auto& p : a) {
    int x, y;
    cin >> x >> y;
    p.real(x), p.imag(y);
  }
  for (int i = 0; i < 4; i++) {
    auto p1 = a[(i + 1) % 4] - a[i];
    auto p2 = a[(i + 1) % 4] - a[(i + 2) % 4];
    if (cross(p1, p2) > 0) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}
