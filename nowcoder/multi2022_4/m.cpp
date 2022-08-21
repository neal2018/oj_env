#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long long;

constexpr auto eps = 0;
const auto PI = acos(-1);
int sgn(ld x) { return (abs(x) <= eps) ? 0 : (x < 0 ? -1 : 1); }

struct Point {
  ld x = 0, y = 0;
  Point() = default;
  Point(ld _x, ld _y) : x(_x), y(_y) {}
  bool operator<(const Point &p) const { return !sgn(p.x - x) ? sgn(y - p.y) < 0 : x < p.x; }
  bool operator==(const Point &p) const { return !sgn(p.x - x) && !sgn(p.y - y); }
  Point operator+(const Point &p) const { return {x + p.x, y + p.y}; }
  Point operator-(const Point &p) const { return {x - p.x, y - p.y}; }
  Point operator*(ld a) const { return {x * a, y * a}; }
  Point operator/(ld a) const { return {x / a, y / a}; }
  auto operator*(const Point &p) const { return x * p.x + y * p.y; }  // dot
  auto operator^(const Point &p) const { return x * p.y - y * p.x; }  // cross
  friend auto &operator>>(istream &i, Point &p) { return i >> p.x >> p.y; }
};

Point perp(const Point &p) { return Point(-p.y, p.x); }

bool polar_cmp(const Point &p1, const Point &p2) {
  Point o{0, 0};
  auto quad = [&](const Point &p) {
    Point a = p - o;
    return (a.y > 0 || (a.y == 0 && a.x > 0)) ? 1 : 2;
  };
  int q1 = quad(p1), q2 = quad(p2);
  if (q1 != q2) return q1 < q2;
  return ((p1 - o) ^ (p2 - o)) > 0;
};

struct UnionFind {
  vector<int> p;
  UnionFind(int n) : p(n) { iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : (p[x] = find(p[x])); }
  void merge(int x, int y) { p[find(x)] = find(y); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<Point> a(n);
  for (auto &x : a) cin >> x;
  a.erase(unique(a.begin(), a.end()), a.end());
  n = int(a.size());
  if (n == 1) {
    cout << "YES\n";
    cout << "0 0 0 1\n";
    return 0;
  }
  vector<Point> b(n - 1);
  for (int i = 0; i < n - 1; i++) b[i] = a[i + 1] - a[i];
  sort(b.begin(), b.end(), polar_cmp);
  b.erase(unique(b.begin(), b.end()), b.end());
  if (b.size() == 1) {
    cout << "YES\n";
    cout << "0 0 " << b[0].x << " " << b[0].y << "\n";
    return 0;
  }
  for (int i = 0; i < b.size(); i++) {
    auto &nex = b[(i + 1) % b.size()];
    if ((b[i] ^ nex) < 0 || ((b[i] ^ nex) == 0 && ((b[i] * nex)) < 0)) {
      // auto t = b[i] ^ b[(i + 1) % b.size()];
      auto c = perp(nex);
      cout << "YES\n";
      cout << "0 0 " << c.x << " " << c.y << "\n";
      return 0;
    }
  }
  cout << "NO\n";
}
