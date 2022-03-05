#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll h, w, n;
  cin >> h >> w >> n;
  ll sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy, sx--, sy--, gx--, gy--;
  map<ll, set<ll>> row, col;
  set<pair<ll, ll>> cannot;
  vector<pair<ll, ll>> a(n);
  for (auto& [x, y] : a) {
    cin >> x >> y, x--, y--;
    row[x].insert(y);
    col[y].insert(x);
    cannot.insert({x, y});
  }
  set<tuple<ll, ll, ll>> st;
  st.insert({0, sx, sy});
  set<pair<ll, ll>> seen{{sx, sy}};
  while (st.size()) {
    auto [cur, x, y] = *st.begin();
    st.erase(st.begin());
    vector<pair<ll, ll>> nex;
    // up
    {
      if (col.count(y)) {
        auto it = col[y].upper_bound(x);
        if (it != col[y].begin()) {
          nex.push_back({*(--it) + 1, y});
        }
      }
    }
    // down
    {
      if (col.count(y)) {
        auto it = col[y].upper_bound(x);
        if (it != col[y].end()) {
          nex.push_back({*it - 1, y});
        }
      }
    }
    // left
    {
      if (row.count(x)) {
        auto it = row[x].upper_bound(y);
        if (it != row[x].begin()) {
          nex.push_back({x, *(--it) + 1});
        }
      }
    }
    // right
    {
      if (row.count(x)) {
        auto it = row[x].upper_bound(y);
        if (it != row[x].end()) {
          nex.push_back({x, *it - 1});
        }
      }
    }
    for (auto& [xx, yy] : nex) {
      if (!seen.count({xx, yy}) && !cannot.count({xx, yy})) {
        if (xx == gx && yy == gy) {
          cout << cur + 1 << "\n";
          return 0;
        }
        st.insert({cur + 1, xx, yy});
        seen.insert({xx, yy});
      }
    }
  }
  cout << "-1\n";
}
