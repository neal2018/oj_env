#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Line = pair<pair<int, int>, pair<int, int>>;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<Line> lines(n);
  int X = 0;
  auto get_y = [&](auto line) {
    // (y1-y2)/(x1-x2)= (y-y1)/(x-x1);
    auto& [p1, p2] = line;
    auto& [x1, y1] = p1;
    auto& [x2, y2] = p2;
    return double(y1 - y2) * (X - x1) / (x1 - x2) + y1;
  };
  auto cmp = [&](auto a, auto b) { return get_y(a.first) > get_y(b.first); };
  vector<array<int, 3>> event;  // x_pos, is_in, id;
  set<pair<Line, int>, decltype(cmp)> st(cmp);
  for (int i = 0; i < n; i++) {
    auto& [p1, p2] = lines[i];
    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    if (p1.first > p2.first) swap(p1, p2);
    event.push_back({p1.first, -1, i});
    event.push_back({p2.first, 1, i});
  }
  int x0, cur_line = -1;
  cin >> x0;
  event.push_back({x0, 2, -1});
  sort(event.begin(), event.end());
  vector<pair<int, int>> to(n, {-1, -1});
  for (auto& [x_pos, is_out, id] : event) {
    X = x_pos;
    if (is_out == -1) {
      int y = lines[id].first.second;
      auto it = st.upper_bound({{{x_pos, y}, {x_pos - 1, y}}, -1});
      if (it != st.end()) to[id].first = it->second;
      st.insert({lines[id], id});
    } else if (is_out == 1) {
      int y = lines[id].second.second;
      auto it = st.upper_bound({{{x_pos, y}, {x_pos - 1, y}}, -1});
      if (it != st.end()) to[id].second = it->second;
      st.erase({lines[id], id});
    } else {
      int y = 2000000;
      auto it = st.upper_bound({{{x_pos, y}, {x_pos - 1, y}}, -1});
      if (it != st.end()) cur_line = it->second;
    }
  }
  // for (auto& [x, y] : to) cout << x << " " << y << "\n";
  while (cur_line != -1) {
    auto& [p1, p2] = lines[cur_line];
    auto& [x1, y1] = p1;
    auto& [x2, y2] = p2;
    if (y1 > y2) {
      x0 = lines[cur_line].second.first;
      cur_line = to[cur_line].second;
    } else {
      x0 = lines[cur_line].first.first;
      cur_line = to[cur_line].first;
    }
  }
  cout << x0 << "\n";
}