#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    ll c = k / 2;
    map<pair<pair<int, int>, pair<int, int>>, ll> mp;
    vector dis(k + 1, vector<ll>(k + 1, 1e18));
    for (int i = 0, x1, y1, x2, y2; i < n; i++) {
      cin >> x1 >> y1 >> x2 >> y2, x1--, y1--, x2--, y2--;
      if (x1 == x2) {
        pair<int, int> p1 = {x1, max(y1, y2)};
        pair<int, int> p2 = {x1 + 1, max(y1, y2)};
        mp[{p1, p2}]++, mp[{p2, p1}]++;
      } else {
        pair<int, int> p1 = {max(x1, x2), y1};
        pair<int, int> p2 = {max(x1, x2), y1 + 1};
        mp[{p1, p2}]++, mp[{p2, p1}]++;
      }
    }
    set<pair<ll, pair<ll, ll>>> st;
    dis[0][0] = 0;
    st.insert({0, {c, c}});
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (true) {
      auto [v, p] = *st.begin();
      st.erase(st.begin());
      if (p.first == 0 || p.first == k || p.second == 0 || p.second == k) {
        cout << n - dis[p.first][p.second] << "\n";
        break;
      }
      pair<int, int> rev = {2 * c - p.first, 2 * c - p.second};
      for (auto& [dx, dy] : directions) {
        pair<int, int> p_nex = {p.first + dx, p.second + dy};
        if (!(0 <= p_nex.first && p_nex.first <= k && 0 <= p_nex.second && p_nex.second <= k))
          continue;
        pair<int, int> rev_nex = {rev.first - dx, rev.second - dy};
        ll nex_cost = v + mp[{p, p_nex}] + mp[{rev, rev_nex}];
        if (nex_cost < dis[p_nex.first][p_nex.second]) {
          dis[p_nex.first][p_nex.second] = min(dis[p_nex.first][p_nex.second], nex_cost);
          st.insert({nex_cost, p_nex});
        }
      }
    }
  }
}
