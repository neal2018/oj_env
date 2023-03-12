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
    vector<array<int, 2>> res;
    int good = 1;
    while (true) {
      auto maxi = max_element(a.begin(), a.end());
      auto mini = min_element(a.begin(), a.end());
      if (*maxi == *mini) break;
      if (*mini == 1) {
        good = 0;
        break;
      }
      res.push_back({int(maxi - a.begin()), int(mini - a.begin())});
      *maxi = (*maxi + *mini - 1) / (*mini);
    }
    if (!good) {
      cout << "-1\n";
    } else {
      cout << res.size() << "\n";
      if (res.size()) {
        for (auto& [x, y] : res) {
          cout << x + 1 << " " << y + 1 << "\n";
        }
      }
    }
  }
}
