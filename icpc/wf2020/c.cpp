#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

using ll = long long;
using ld = long double;

constexpr auto eps = 1e-8;
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
  friend auto &operator<<(ostream &o, Point p) { return o << p.x << ' ' << p.y; }
};

struct Line {
  Point s = {0, 0}, e = {0, 0};
  Line() = default;
  Line(Point _s, Point _e) : s(_s), e(_e) {}
  friend auto &operator>>(istream &i, Line &l) { return i >> l.s >> l.e; }  // ((x1, y1), (x2, y2)
};

auto rad(const Point &p) { return atan2(p.y, p.x); }

Point intersect(const Line &a, const Line &b) {
  auto u = a.e - a.s, v = b.e - b.s;
  auto t = ((b.s - a.s) ^ v) / (u ^ v);
  return a.s + u * t;
}

vector<Point> half_plane_intersect(vector<Line> &L) {
  int n = (int)L.size(), l = 0, r = 0;  // [left, right]
  sort(L.begin(), L.end(),
       [](const Line &a, const Line &b) { return rad(a.s - a.e) < rad(b.s - b.e); });
  vector<Point> p(n), res;
  vector<Line> q(n);
  q[0] = L[0];
  for (int i = 1; i < n; i++) {
    while (l < r && sgn((L[i].e - L[i].s) ^ (p[r - 1] - L[i].s)) <= 0) r--;
    while (l < r && sgn((L[i].e - L[i].s) ^ (p[l] - L[i].s)) <= 0) l++;
    q[++r] = L[i];
    if (sgn((q[r].e - q[r].s) ^ (q[r - 1].e - q[r - 1].s)) == 0) {
      r--;
      if (sgn((q[r].e - q[r].s) ^ (L[i].s - q[r].s)) > 0) q[r] = L[i];
    }
    if (l < r) p[r - 1] = intersect(q[r - 1], q[r]);
  }
  while (l < r && sgn((q[l].e - q[l].s) ^ (p[r - 1] - q[l].s)) <= 0) r--;
  if (r - l <= 1) return {};
  p[r] = intersect(q[r], q[l]);
  return vector<Point>(p.begin() + l, p.begin() + r + 1);
}

auto area(const vector<Point> &p) {
  int n = (int)p.size();
  long double area = 0;
  for (int i = 0; i < n; i++) area += p[i] ^ p[(i + 1) % n];
  return area / 2.0;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(20);
  ld dx, dy;
  int n;
  std::cin >> dx >> dy >> n;
  std::vector<std::array<ld, 2>> a(n);
  for (auto &[x, y] : a) std::cin >> x >> y;
  std::vector<int> p(n);
  for (auto &x : p) std::cin >> x, x--;

  std::vector<Line> lines = {
      {{0, 0}, {dx, 0}},
      {{dx, 0}, {dx, dy}},
      {{dx, dy}, {0, dy}},
      {{0, dy}, {0, 0}},
  };

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      lines.push_back({{a[p[j]][0], a[p[j]][1]}, {a[p[i]][0], a[p[i]][1]}});
    }
  }
  auto convex = half_plane_intersect(lines);
  auto res = area(convex);
  std::cout << res << "\n";
}
