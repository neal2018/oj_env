#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, h, k;
  string s;
  cin >> n >> m >> h >> k >> s;
  set<array<int, 2>> st;
  for (int i = 0, x, y; i < n; i++) {
    cin >> x >> y, st.insert({x, y});
  }
  auto consume = [&](int x, int y) {
    if (h < k && st.count({x, y})) {
      h = k, st.erase({x, y});
    }
  };
  int x = 0, y = 0;
  map<char, array<int, 2>> mp = {{'R', {1, 0}}, {'L', {-1, 0}}, {'U', {0, 1}}, {'D', {0, -1}}};
  for (auto& c : s) {
    auto [dx, dy] = mp[c];
    x += dx, y += dy, h--;
    if (h < 0) {
      cout << "No\n";
      return 0;
    }
    consume(x, y);
  }
  cout << "Yes\n";
}
