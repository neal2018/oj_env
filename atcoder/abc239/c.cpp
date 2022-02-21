#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  vector<pair<int, int>> d = {{-2, -1}, {-1, -2}, {1, 2},  {2, 1},
                              {-1, 2},  {2, -1},  {1, -2}, {-1, 2}};
  set<pair<ll, ll>> st;
  for (auto& [dx, dy] : d) {
    st.insert({x1 + dx, y1 + dy});
  }
  for (auto& [dx, dy] : d) {
    if (st.count({x2 + dx, y2 + dy})) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
}
