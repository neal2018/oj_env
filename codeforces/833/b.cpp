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
    vector<pair<int, int>> res;
    for (int i = 0, j = 3 * n - 1; i < j; i += 3, j -= 3) {
      res.push_back({i, j});
    }
    cout << res.size() << "\n";
    for (auto& [x, y] : res) {
      cout << x + 1 << " " << y + 1 << "\n";
    }
  }
}
