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

auto dist2(const Point &a) { return a * a; }
auto dist(const Point &a) { return sqrt(dist2(a)); }

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(20);
  int n;
  i64 t;
  std::cin >> n >> t;
  std::vector<Point> a(n);
  for (auto &x : a) std::cin >> x;
  int res = 1;

  for (int i = 0; i < n; i++) {
    std::vector<std::tuple<ld, int>> events;
    auto add = [&](ld start, ld end) {
      while (start > PI) start -= 2 * PI;
      while (start < -PI) start += 2 * PI;
      while (end > PI) end -= 2 * PI;
      while (end < -PI) end += 2 * PI;
      if (start < end) {
        events.emplace_back(start, -1);
        events.emplace_back(end, 1);
      } else {
        events.emplace_back(-PI, -1);
        events.emplace_back(end, 1);
        events.emplace_back(start, 1);
        events.emplace_back(PI, 1);
      }
    };
    int cnt = 1;
    // -1: in, 1: out
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      auto s1 = rad(a[j] - a[i]);
      auto s2 = rad(a[i] - a[j]);

      auto d = dist(a[j] - a[i]);
      if (d < t) {
        add(s1, s2);
      } else {
        auto range = asin(t / d);
        add(s1, s1 + range);
        add(s2 - range, s2);
      }
    }
    std::sort(events.begin(), events.end());
    int sz = int(events.size());
    for (auto &[_, type] : events) {
      cnt -= type;
      res = std::max(res, cnt);
    }
  }

  std::cout << res << "\n";
}
