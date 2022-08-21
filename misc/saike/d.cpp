#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll c;
  cin >> c;
  if (c < 4 || (c & 1)) {
    cout << "-1\n";
    return 0;
  }
  vector<array<ll, 3>> points;
  ll half = c / 2;
  for (ll i = 0; i <= c; i++) {
    for (ll j = 0; i * i + j * j <= half * half; j++) {
      if (i == 0 && j == 0) continue;
      ll t = ll(sqrt(i * i + j * j));
      if (t * t == i * i + j * j) points.push_back({i, j, t});
    }
  }
  ll res = inf;
  for (int i = 0; i < points.size(); i++) {
    for (int j = i + 1; j < points.size(); j++) {
      auto [x1, y1, l1] = points[i];
      auto [x2, y2, l2] = points[j];
      ll tt = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
      ll t = ll(sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
      if (t * t == tt) {
        if (t + l1 + l2 == c && x1 * y2 != y1 * x2) {
          ll mini = min({t, l1, l2});
          ll maxi = max({t, l1, l2});
          res = min(res, maxi - mini);
        }
      }
    }
  }
  if (res != inf) {
    cout << res << "\n";
  } else {
    if (c % 4) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }
}
