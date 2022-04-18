#include <bits/stdc++.h>
using namespace std;

#define FOR(x, n) for (int x = 0; x < n; x++)
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const char nl = '\n';

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);

  int n;
  cin >> n;

  int l = (1 << n);
  vector<pii> positions[(l * l + 5)];
  FOR(i, l) FOR(j, l) {
    int w;
    cin >> w;
    if (w != 0) positions[w].push_back({i, j});
  }

  bool ok = true;
  for (int i = 1; i <= (l * l - 1) / 3; i++) {
    if ((int)positions[i].size() != 3) {
      ok = false;
      break;
    }
    int dx = 0, dy = 0;
    FOR(j, 3) FOR(k, 3) {
      auto [x1, y1] = positions[i][j];
      auto [x2, y2] = positions[i][k];
      dx = max(dx, abs(x1 - x2));
      dy = max(dy, abs(y1 - y2));
    }
    if (dx != 1 || dy != 1) {
      ok = false;
      break;
    }
  }

  if (ok)
    cout << "1\n";
  else
    cout << "0\n";
}