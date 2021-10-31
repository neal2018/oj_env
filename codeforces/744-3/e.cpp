#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, x;
  cin >> T;
  while (T--) {
    cin >> n;
    deque<int> a;
    for (int i = 0; i < n; i++) {
      cin >> x;
      if (a.size() == 0) {
        a.push_back(x);
      } else {
        if (x < a[0]) {
          a.push_front(x);
        } else {
          a.push_back(x);
        }
      }
    }
    for (auto& x : a) cout << x << " ";
    cout << endl;
  }
}