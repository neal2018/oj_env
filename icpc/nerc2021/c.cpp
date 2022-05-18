#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<int,int>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);

  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  int miny = min({y1, y2, y3});
  int maxy = max({y1, y2, y3});

  ii p1 = {x1, y1};
  ii p2 = {x2, y2};
  ii p3 = {x3, y3};
  vector<ii> pts = {p1, p2, p3};
  sort(pts.begin(), pts.end());

  int midx = pts[1].first;
  vector<pair<ii,ii>> segs = {{{midx, miny}, {midx, maxy}}};
  segs.push_back({pts[0], {midx, pts[0].second}});
  segs.push_back({pts[2], {midx, pts[2].second}});
  vector<pair<ii,ii>> ans;
  for(auto [s, e] : segs) {
    if(s == e) continue;
    ans.push_back({s , e});
  }

  cout << (int)ans.size() << '\n';
  for(auto [s, e] : ans) {
    auto [a, b] = s;
    auto [c, d] = e;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
  }
}