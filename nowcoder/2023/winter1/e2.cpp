#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

constexpr ld eps = 1e-9;

struct Point {
  ld x, y;
};

Point operator-(const Point& p, const Point& q) { return {p.x - q.x, p.y - q.y}; }
ld norm(const Point& p) { return p.x * p.x + p.y * p.y; }
ld cross(const Point& p, const Point& q) { return p.x * q.y - p.y * q.x; }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    vector<Point> a(3), b(3);
    for (auto& v : {ref(a), ref(b)}) {
      for (auto& p : v.get()) {
        cin >> p.x >> p.y;
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