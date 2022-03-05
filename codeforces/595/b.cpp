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
    vector<int> a(n);
    for (auto& x : a) cin >> x, x--;
    vector<int> seen(n), res(n);
    for (int i = 0; i < n; i++) {
      if (seen[i]) continue;
      int cnt = 0, j = i;
      while (!seen[j]) {
        seen[j] = 1, j = a[j], cnt++;
      }
      j = i;
      while (!res[j]) {
        res[j] = cnt, j = a[j];
      }
    }
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}
