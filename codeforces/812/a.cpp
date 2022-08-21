#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    int minx = 0, miny = 0, maxx = 0, maxy = 0;
    for (auto& [x, y] : a) {
      cin >> x >> y;
      minx = min(minx, x);
      miny = min(miny, y);
      maxx = max(maxx, x);
      maxy = max(maxy, y);
    }
    cout << 2 * (abs(minx) + abs(miny) + abs(maxx) + abs(maxy)) << "\n";
  }
}
