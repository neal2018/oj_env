#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  string a, b;
  cin >> T;
  while (T--) {
    cin >> n >> a >> b;
    int a0 = 0, a1 = 0, b0 = 0, b1 = 0;
    for (int i = 0; i < n; i++) {
      a[i] == '0' ? a0++ : a1++;
      b[i] == '0' ? b0++ : b1++;
    }
    if (a0 == n && b0 != n) {
      cout << "-1\n";
      continue;
    }
    int mini = 1e9;
    if (a0 == b0) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) cnt += 1;
      }
      if (cnt % 2 == 0) mini = min(mini, cnt);
    }
    if (a1 - 1 == b0) {
      int cnt = 0, index = -1;
      for (int i = 0; i < n; i++) {
        if (a[i] == '1' && b[i] == '1') index = i;
      }
      for (int i = 0; i < n; i++) {
        if (i == index) {
          continue;
        } else {
          a[i] = (a[i] == '0' ? '1' : '0');
        }
      }
      for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) cnt += 1;
      }
      if (cnt % 2 == 0) mini = min(mini, cnt + 1);
    }
    cout << (mini == 1e9 ? -1 : mini) << '\n';
  }
}