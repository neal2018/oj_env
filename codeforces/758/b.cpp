#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, a, b;
  cin >> T;
  while (T--) {
    cin >> n >> a >> b;
    if (abs(a - b) > 1 || a + b > n - 2) {
      cout << -1 << '\n';
    } else {
      int rev = 0, cur = 1, pos = 0;
      if (a > b) swap(a, b), rev = 1;
      vector<int> res(n);
      if (a == b) {
        res[0] = cur++, pos = 2;
      } else {
        res[0] = n, pos = 1;
      }
      for (int i = 0; i < b; i++) res[pos] = cur++, pos += 2;
      for (int i = 0; i < n; i++)
        if (res[i] == 0) res[i] = cur++;
      for (int i = 0; i < n; i++) {
        if (rev)
          cout << n - res[i] + 1;
        else
          cout << res[i];
        cout << " ";
      }
      cout << "\n";
    }
  }
}