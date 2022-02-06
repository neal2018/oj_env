#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a) cin >> x, x = (x >= m ? 1 : 0);
    vector<int> cut;
    int cur = 0, has = 0;
    for (int i = 0; i < n; i++) {
      has = 1;
      if (a[i] == 1) {
        cur++;
      } else {
        cur--;
      }
      if (cur > 0) {
        cut.push_back(cur);
        cur = 0;
        has = 0;
      }
    }
    if (!has) {
      cout << cut.size() << "\n";
    } else {
      if (-cur + 1 > cut.size()) {
        cout << -1 << "\n";
      } else {
        cout << (int)cut.size() + cur << "\n";
      }
    }
  }
}
