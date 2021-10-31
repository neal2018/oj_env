#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    deque<int> a(n);
    vector<tuple<int, int, int>> res;
    for (auto& x : a) cin >> x;
    for (int i = 0; i < n; i++) {
      int mini = 0;
      for (int j = 0; j < n - i; j++) {
        if (a[mini] > a[j]) {
          mini = j;
        }
      }
      if (mini != 0) {
        res.push_back({mini, i + 1, n});
        while (mini--) {
          int x = a[0];
          a.pop_front();
          a.push_back(x);
        }
      }
      // cout << a[0] << " ";
      a.pop_front();
    }
    // cout << endl;
    cout << res.size() << endl;
    for (auto& [x, y, z] : res) {
      cout << y << " " << z << " " << x << '\n';
    }
    // cout << endl;
  }
}