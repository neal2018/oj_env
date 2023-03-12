#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int sx, sy, tx, ty, a, b, c, d;
  cin >> sx >> sy >> tx >> ty >> a >> b >> c >> d;
  if ((sx - tx) % 2 != 0 || (sy - ty) % 2 != 0) {
    cout << "No\n";
    return 0;
  }

  vector<array<int, 2>> res;

  auto move = [&](int x, int y) {
    res.push_back({x, y});
    sx = 2 * x - sx;
    sy = 2 * y - sy;
  };

  if (a == b && (sx != tx)) {
    move(a, c);
  }

  if (c == d && (sy != ty)) {
    move(a, c);
  }

  if (a == b) {
    if (sx != tx) {
      cout << "No\n";
      return 0;
    }
  } else {
    while (sx < tx) {
      move(a, c);
      move(a + 1, c);
    }
    while (sx > tx) {
      move(a + 1, c);
      move(a, c);
    }
  }

  if (c == d) {
    if (sy != ty) {
      cout << "No\n";
      return 0;
    }
  } else {
    while (sy < ty) {
      move(a, c);
      move(a, c + 1);
    }
    while (sy > ty) {
      move(a, c + 1);
      move(a, c);
    }
  }

  cout << "Yes\n";
  for (auto& [x, y] : res) {
    cout << x << " " << y << "\n";
  }
}
