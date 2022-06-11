#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

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
};

ld operator*(const Point &q, const Point &p) { return q.x * p.x + q.y * p.y; }  // dot
ld operator^(const Point &q, const Point &p) { return q.x * p.y - q.y * p.x; }  // cross

struct Line {
  Point s = {0, 0}, e = {0, 0};
  Line() = default;
  Line(Point _s, Point _e) : s(_s), e(_e) {}
};

struct Segment : Line {
  using Line::Line;
};

ld dist2(const Point &a) { return a * a; }
ld dist2(const Point &a, const Point &b) { return dist2(a - b); }
ld dist(const Point &a) { return sqrt(dist2(a)); }
ld dist(const Point &a, const Point &b) { return sqrt(dist2(a - b)); }
ld dist(const Point &a, const Line &l) { return abs((a - l.s) ^ (l.e - l.s)) / dist(l.s, l.e); }
ld dist(const Point &p, const Segment &l) {
  if (l.s == l.e) return dist(p, l.s);
  auto d = dist2(l.s, l.e), t = min(d, max((ld)0, (p - l.s) * (l.e - l.s)));
  return dist((p - l.s) * d, (l.e - l.s) * t) / d;
}

vector<Point> get_convex2(vector<Point> &points,
                          bool allow_collinear = false) {  // strict, no repeat, one pass
  nth_element(points.begin(), points.begin(), points.end());
  sort(points.begin() + 1, points.end(), [&](const Point &a, const Point &b) {
    int rad_diff = sgn((a - points[0]) ^ (b - points[0]));
    return !rad_diff ? (dist2(a - points[0]) < dist2(b - points[0])) : (rad_diff > 0);
  });
  if (allow_collinear) {
    int i = (int)points.size() - 1;
    while (i >= 0 && !sgn((points[i] - points[0]) ^ (points[i] - points.back()))) i--;
    reverse(points.begin() + i + 1, points.end());
  }
  vector<Point> hull;
  for (auto &t : points) {
    for (ll sz = hull.size();
         sz > 1 && (sgn((t - hull[sz - 2]) ^ (hull[sz - 1] - hull[sz - 2])) >= allow_collinear);
         hull.pop_back(), sz = hull.size()) {
    }
    hull.push_back(t);
  }
  return hull;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int caseno = 1;
  cout << setprecision(2) << fixed;
  while (1) {
    int n;
    cin >> n;
    if (n == 0) exit(0);
    if(caseno > 1) cout << endl;
    vector<Point> poly(n);
    for (int i = 0; i < n; i++) cin >> poly[i].x >> poly[i].y;
    auto hull = get_convex2(poly);
    n = (int)hull.size();
    ld ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      Line l(hull[i], hull[(i + 1) % n]);
      ld mxdist = 0;
      for (auto pt : hull) mxdist = max(mxdist, dist(pt, l));
      ans = min(ans, mxdist);
    }
    ld asdf = floor(ans*100);
    if(100*ans - asdf < eps) ans = floor(ans*100)/100.0;
    else ans = ceil(ans * 100)/100.0;
    cout << "Case " << caseno << ": " << ans;
    caseno++;
  }
}
