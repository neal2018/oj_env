#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

constexpr ld eps = 1e-9;

auto dot(complex<ld> x, complex<ld> y) { return (conj(x) * y).real(); }
auto cross(complex<ld> x, complex<ld> y) { return (conj(x) * y).imag(); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    vector<complex<ld>> a(3), b(3);
    for (auto& v : {ref(a), ref(b)}) {
      for (auto& p : v.get()) {
        ld x, y;
        cin >> x >> y, p.real(x), p.imag(y);
      }
    }

    if (cross(a[0] - a[1], a[2] - a[1]) * cross(b[0] - b[1], b[2] - b[1]) < 0) swap(b[0], b[2]);
    if (abs(sqrt(norm(a[0] - a[1])) - sqrt(norm(b[0] - b[1]))) < eps) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}