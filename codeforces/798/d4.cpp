#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> dist(4, -n - m);
    auto get = [&](int i, int j, int t) {
      return (2 * (t & 1) - 1) * i + (2 * ((t & 2) == 2) - 1) * j;
    };
    for (auto i : views::iota(0, n)) {
      for (char c; auto j : views::iota(0, m)) {
        cin >> c;
        if (c == 'B') {
          for (auto t : views::iota(0, 4)) dist[t] = max(dist[t], get(i, j, t));
        }
      }
    }
    int x = -1, y = -1, res = 1e9;
    for (auto i : views::iota(0, n)) {
      for (auto j : views::iota(0, m)) {
        int cost = ranges::max(views::iota(0, 4) |
                               views::transform([&](int t) { return dist[t] - get(i, j, t); }));
        if (cost < res) res = cost, x = i, y = j;
      }
    }
    cout << x + 1 << " " << y + 1 << "\n";
  }
}
