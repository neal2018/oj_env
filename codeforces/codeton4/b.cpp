#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    [&] {
      vector<int> res;
      while (n > 1) {
        if (n % 2 == 0) {
          cout << "-1\n";
          return;
        }
        if (((n - 1) / 2) % 2 == 1) {
          res.push_back(2);
          n = (n - 1) / 2;
        } else if (((n + 1) / 2) % 2 == 1) {
          res.push_back(1);
          n = (n + 1) / 2;
        } else {
          cout << "-1\n";
          return;
        }
      }
      reverse(res.begin(), res.end());
      cout << res.size() << "\n";
      for (auto& x : res) cout << x << " ";
      cout << "\n";
    }();
  }
}
