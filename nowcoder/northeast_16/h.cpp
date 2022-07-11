#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll greedy(vector<array<ll, 2>>& mouse, vector<array<ll, 3>>& hole) {
  constexpr ll inf = 1e18;
  ll n = mouse.size(), m = hole.size();
  ll total = 0, need = 0;
  for (auto& [x, y] : mouse) need += y;
  for (auto& [x, y, z] : hole) total += z;
  if (total < need) return -1;
  ll res = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q0, q1;
  auto insert_mouse = [&](ll pos, ll count) {
    while (count) {
      auto [val, d] = q1.top();
      q1.pop();
      ll add = min(count, d);
      res += (val + pos) * add;
      if (d > add) q1.emplace(val, d - add);
      q0.emplace(-pos * 2 - val, add);
      count -= add;
    }
  };
  auto insert_hole = [&](ll pos, ll weight, ll count) {
    ll f = 0;
    for (; f < count && q0.size() && q0.top().first + pos + weight < 0;) {
      auto [val, d] = q0.top();
      q0.pop();
      ll add = min(d, count - f);
      res += (val + pos + weight) * add;
      f += add;
      if (d > add) q0.emplace(val, d - add);
      q1.emplace(-pos * 2 - val, add);
    }
    if (f < count) q1.emplace(-pos + weight, count - f);
    if (f) q0.emplace(-pos - weight, f);
  };
  insert_hole(-inf, 0, need);
  for (int i = 0, j = 0; i < n || j < m;) {
    if (j == m || (i != n && mouse[i][0] <= hole[j][0])) {
      insert_mouse(mouse[i][0], mouse[i][1]), i++;
    } else {
      insert_hole(hole[j][0], hole[j][1], hole[j][2]), j++;
    }
  }
  return res;
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<array<ll, 2>> mouse(10);
    for (int i = 0; i < 10; i++) mouse[i] = {i, 0};
    for (auto& c : s) mouse[c - '0'][1]++;
    vector<array<ll, 3>> hole(10);
    for (int i = 0; i < 10; i++) hole[i] = {i, 0, m};
    auto cost = greedy(mouse, hole);
    ll already = 0;
    string res(n, '?');
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 10; j++) {
        ll cur_cost = already + abs(s[i] - '0' - j);
        if (hole[j][2] == 0) continue;
        mouse[s[i] - '0'][1]--;
        hole[j][2]--;
        auto flow = greedy(mouse, hole);
        if (flow + cur_cost == cost) {
          res[i] = char(j + '0');
          already += abs(s[i] - '0' - j);
          break;
        }
        mouse[s[i] - '0'][1]++;
        hole[j][2]++;
      }
    }
    cout << cost << "\n";
    cout << res << "\n";
  }
}
