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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int black = a[0] & 1;
    vector<int> blacks, whites;
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == black) {
        blacks.push_back(i);
      } else {
        whites.push_back(i);
      }
    }
    vector<pair<int, int>> res;
    for (int i = int(blacks.size()) - 1; i > 0; i--) {
      res.push_back({blacks[i - 1], blacks[i]});
    }
    for (int i = 0; i < whites.size(); i++) {
      res.push_back({0, whites[i]});
    }
    cout << res.size() << "\n";
    for (auto& [x, y] : res) cout << x + 1 << " " << y + 1 << "\n";
  }
}
