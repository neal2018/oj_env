#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, m, a, b, c;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    vector<int> t(n);
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> c;
      t[b - 1] = 1;
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
      if (t[i] == 0) {
        index = i;
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i != index) {
        cout << index + 1 << " " << i + 1 << '\n';
      }
    }
  }
}