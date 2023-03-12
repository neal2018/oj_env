#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

constexpr ld inf = 1e20;

constexpr ll MOD = (1ll << 31) - 1;
ll seed;
ll gen() { return seed = (seed * 233811181 + 1) % MOD; }

constexpr ld eps = 1e-9;

struct Point {
  ld x, y;
  Point(ll xx = 0, ll yy = 0) : x(xx), y(yy) {}
};

auto dist(const Point& a, const Point& b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int sgn(ld x) { return (abs(x) <= eps) ? 0 : (x < 0 ? -1 : 1); }

Point get_o(Point a, Point b, Point c) {
  auto a1 = 2 * (b.x - a.x), b1 = 2 * (b.y - a.y);
  auto c1 = b.x * b.x - a.x * a.x + b.y * b.y - a.y * a.y;
  auto a2 = 2 * (c.x - a.x), b2 = 2 * (c.y - a.y);
  auto c2 = c.x * c.x - a.x * a.x + c.y * c.y - a.y * a.y;
  Point res;
  if (!sgn(a1)) {
    res.y = c1 / b1;
    res.x = (c2 - res.y * b2) / a2;
  } else if (!sgn(b1)) {
    res.x = c1 / a1;
    res.y = (c2 - res.x * a2) / b2;
  } else {
    res.x = (c2 * b1 - c1 * b2) / (a2 * b1 - a1 * b2);
    res.y = (c2 * a1 - c1 * a2) / (b2 * a1 - b1 * a2);
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, kk;
  cin >> n >> kk >> seed;
  vector<Point> p(n, {seed, gen()});
  for (int i = 1; i < n; i++) {
    p[i] = {gen(), gen()};
  }
  vector<vector<ld>> cost(n, vector<ld>(n));
  vector<array<int, 2>> links;
  // minimum circle cover
  for (int start = 0; start < n; start++) {
    auto o = p[start];
    ld r = 0;
    for (int i = start; i < n; i++) {
      if (dist(o, p[i]) <= r + eps) {
        cost[start][i] = r;
        continue;
      }
      links.push_back({start, i - 1});
      o.x = (p[i].x + p[start].x) / 2;
      o.y = (p[i].y + p[start].y) / 2;
      r = dist(p[i], p[start]) / 2;
      for (int j = start + 1; j < i; j++) {
        if (dist(o, p[j]) <= r + eps) continue;
        o.x = (p[i].x + p[j].x) / 2;
        o.y = (p[i].y + p[j].y) / 2;
        r = dist(p[i], p[j]) / 2;
        for (int k = start; k < j; k++) {
          if (dist(o, p[k]) <= r + eps) continue;
          o = get_o(p[i], p[j], p[k]);
          r = dist(o, p[i]);
        }
      }
      cost[start][i] = r;
    }
    links.push_back({start, n - 1});
  }

  vector<ld> dp(n, inf);
  for (int _ = 0; _ < kk; _++) {
    vector<ld> ndp(n, inf);
    for (auto& [i, j] : links) {
      ndp[j] = min(ndp[j], (i == 0 ? 0 : dp[i - 1]) + cost[i][j]);
    }
    swap(ndp, dp);
  }
  cout << fixed << setprecision(10);
  cout << dp[n - 1] << "\n";
}
