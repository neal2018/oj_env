#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define P pair<ll, ll>
#define x first
#define y second

double INF = 1e18;
double product(P& p1, P& p2, P& p3) {
  return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}
bool is_in_triangle(P& p1, P& p2, P& p3, P& o) {
  if (product(p1, p2, p3) < 0) return is_in_triangle(p1, p3, p2, o);
  if (product(p1, p2, o) > 0 && product(p2, p3, o) > 0 && product(p3, p1, o) > 0) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll total_cases_number, n, xs, ys, xx, yy;
  cin >> total_cases_number;
  cout << fixed << setprecision(9);
  for (ll case_num = 1; case_num <= total_cases_number; case_num++) {
    cin >> n;
    vector<P> p(n);
    double res = INF;
    for (int i = 0; i < n; i++) {
      cin >> xx >> yy;
      p[i] = {xx, yy};
    }
    cin >> xs >> ys;
    P t = {xs, ys};
    auto dis = [&](P& p1, P& p2) {
      return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    };
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        for (int k = j + 1; k < n; k++)
          if (is_in_triangle(p[i], p[j], p[k], t))
            res = min(res, dis(p[i], p[j]) + dis(p[i], p[k]) + dis(p[k], p[j]));

    vector<pair<P, P>> ps;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (product(p[i], p[j], t) == 0 && min(p[i].x, p[j].x) <= xs && min(p[i].y, p[j].y) <= ys &&
            max(p[i].x, p[j].x) >= xs && max(p[i].y, p[j].y) >= ys)
          ps.push_back({p[i], p[j]});

    for (int i = 0; i < ps.size(); i++)
      for (int j = i + 1; j < ps.size(); j++)
        if (product(ps[i].x, ps[j].x, ps[j].y) != 0)
          res = min(res, dis(ps[i].x, ps[j].x) + dis(ps[i].x, ps[j].y) + dis(ps[i].y, ps[j].x) +
                             dis(ps[i].y, ps[j].y));

    cout << "Case #" << case_num << ": ";
    if (abs(res - INF) < 1e-6)
      cout << "IMPOSSIBLE" << '\n';
    else
      cout << res << '\n';
  }
  return 0;
}