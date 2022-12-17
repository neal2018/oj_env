#include <bits/stdc++.h>
using namespace std;
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
auto dist2(const Point &a) { return a * a; }
auto dist2(const Point &a, const Point &b) { return dist2(a - b); }
auto dist(const Point &a) { return sqrt(dist2(a)); }
auto dist(const Point &a, const Point &b) { return sqrt(dist2(a - b)); }

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
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  vector<Point> a(n);
  for (auto &point : a) {
    ll c;
    cin >> point.x >> point.y >> c;
    point.x = point.x / c, point.y = point.y / c;
  }
  ld res = max(a[0].x, a[0].y);
  for (auto &point : a) {
    res = min(res, max(point.x, point.y));
  }
  auto hull = get_convex2(a);
  int sz = int(hull.size());
  for (int i = 0; i < sz; i++) {
    auto [ah, ap] = hull[i];
    auto [bh, bp] = hull[(i + 1) % sz];
    ld l = 0, r = 1;
    while (r - l >= eps) {
      ld mid1 = (l + l + r) / 3, mid2 = (l + r + r) / 3;
      ld p1 = max((mid1 * ah + (1 - mid1) * bh), (mid1 * ap + (1 - mid1) * bp));
      ld p2 = max((mid2 * ah + (1 - mid2) * bh), (mid2 * ap + (1 - mid2) * bp));
      if (p1 < p2) {
        r = mid2;
      } else {
        l = mid1;
      }
      res = min({res, p1, p2});
    }
  }
  cout << 1 / res << "\n";
}
