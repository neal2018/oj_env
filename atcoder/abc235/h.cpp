#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long long;

constexpr auto eps = 1e-8;
const auto PI = acos(-1);
int sgn(ld x) { return (abs(x) <= eps) ? 0 : (x < 0 ? -1 : 1); }

struct Point {
  ld x = 0, y = 0, id = 0;
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

struct Line {
  Point s = {0, 0}, e = {0, 0};
  Line() = default;
  Line(Point _s, Point _e) : s(_s), e(_e) {}
};

struct Segment : Line {
  using Line::Line;
};

struct Circle {
  Point o = {0, 0};
  ld r = 0;
  Circle() = default;
  Circle(Point _o, ld _r) : o(_o), r(_r) {}
};

auto dist2(const Point &a) { return a * a; }
auto dist2(const Point &a, const Point &b) { return dist2(a - b); }

struct Rectangle {
  ld lx, rx, ly, ry;
};

bool is_in(const Point &p, const Rectangle &rg) {
  return (p.x >= rg.lx) && (p.x <= rg.rx) && (p.y >= rg.ly) && (p.y <= rg.ry);
}

struct KDTree {
  vector<Point> points;
  struct Node {
    int lc, rc;
    Point point;
    Rectangle range;
    int l, r;
  };
  vector<Node> nodes;
  int root = -1;
  KDTree(const vector<Point> &_points) {
    points = _points;
    Rectangle range = {(ld)-1e9, (ld)1e9, (ld)-1e9, (ld)1e9};
    root = tree_construct(0, (int)points.size(), range, 0);
  }

  int tree_construct(int l, int r, Rectangle range, int depth) {
    if (l == r) return -1;
    if (l > r) throw;
    int mid = (l + r) / 2;
    auto comp = (depth % 2) ? [](Point &a, Point &b) { return a.x < b.x; }
                            : [](Point &a, Point &b) { return a.y < b.y; };
    nth_element(points.begin() + l, points.begin() + mid, points.begin() + r, comp);
    Rectangle l_range(range), r_range(range);
    if (depth % 2) {
      l_range.rx = points[mid].x;
      r_range.lx = points[mid].x;
    } else {
      l_range.ry = points[mid].y;
      r_range.ly = points[mid].y;
    }
    Node node;
    node.lc = tree_construct(l, mid, l_range, depth + 1);
    node.rc = tree_construct(mid + 1, r, r_range, depth + 1);
    node.l = l;
    node.r = r;
    node.point = points[mid];
    node.range.lx = node.range.rx = node.point.x;
    node.range.ly = node.range.ry = node.point.y;
    for (int son : {node.lc, node.rc}) {
      if (son != -1) {
        node.range.lx = min(node.range.lx, nodes[son].range.lx);
        node.range.rx = max(node.range.rx, nodes[son].range.rx);
        node.range.ly = min(node.range.ly, nodes[son].range.ly);
        node.range.ry = max(node.range.ry, nodes[son].range.ry);
      }
    }
    nodes.push_back(node);
    return (int)nodes.size() - 1;
  }

  vector<ll> query(const Rectangle &rec, ll pid, ll k) {
    vector<ll> res;
    function<void(int, int)> inner_query = [&](int id, int depth) {
      if (id == -1) return;
      Rectangle rg = nodes[id].range;
      if (rg.lx >= rec.lx && rg.rx <= rec.rx && rg.ly >= rec.ly && rg.ry <= rec.ry) {
        for (int i = nodes[id].l; i < nodes[id].r; i++) {
          if (dist2(points[i] - points[pid]) <= k * k) {
            res.push_back(points[i].id);
          }
        }
        return;
      }
      int lc = nodes[id].lc, rc = nodes[id].rc;
      if (depth % 2) {
        if (lc != -1 && rec.lx <= nodes[lc].range.rx) inner_query(nodes[id].lc, depth + 1);
        if (rc != -1 && rec.rx >= nodes[rc].range.lx) inner_query(nodes[id].rc, depth + 1);
      } else {
        if (lc != -1 && rec.ly <= nodes[lc].range.ry) inner_query(nodes[id].lc, depth + 1);
        if (rc != -1 && rec.ry >= nodes[rc].range.ly) inner_query(nodes[id].rc, depth + 1);
      }
      if (dist2(nodes[id].point - points[pid]) <= k * k) {
        res.push_back(nodes[id].point.id);
      }
    };
    inner_query(root, 0);
    return res;
  }
};

int main() {
  ll n, k;
  cin >> n >> k;
  vector<Point> ps(n);
  for (int i = 0; i < n; i++) {
    cin >> ps[i].x >> ps[i].y;
    ps[i].id = i + 1;
  }
  KDTree tree(ps);
  vector<pair<ll, ll>> res;
  for (int i = 0; i < n; i++) {
    auto &p = tree.points[i];
    Rectangle r{p.x - k, p.x + k, p.y - k, p.y + k};
    auto temp = tree.query(r, i, k);
    for (auto x : temp) {
      if (x != p.id) {
        res.push_back({min(x, p.id), max(x, p.id)});
      }
    }
  }
  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());
  cout << res.size() << "\n";
  for (auto &[x, y] : res) {
    cout << x << " " << y << "\n";
  }
}