#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, t;
  cin >> n;
  vector<pair<int, int>> a, b;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (abs(i - j) & 1) {
        a.push_back({i, j});
      } else {
        b.push_back({i, j});
      }
    }
  }
  // a:2, b:3
  for (int i = 0; i < n * n; i++) {
    cin >> t;
    if (t != 3) {
      if (a.size()) {
        auto [x, y] = a.back();
        a.pop_back();
        cout << 3 << ' ' << x + 1 << ' ' << y + 1 << endl;
      } else {
        auto [x, y] = b.back();
        b.pop_back();
        int p = (t == 1 ? 2 : 1);
        cout << p << ' ' << x + 1 << ' ' << y + 1 << endl;
      }
    } else {  // t==3
      if (b.size()) {
        auto [x, y] = b.back();
        b.pop_back();
        cout << 2 << ' ' << x + 1 << ' ' << y + 1 << endl;
      } else {
        auto [x, y] = a.back();
        a.pop_back();
        cout << 1 << ' ' << x + 1 << ' ' << y + 1 << endl;
      }
    }
  }
}