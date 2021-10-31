#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  string n;
  cin >> T;
  while (T--) {
    cin >> n;
    int sz = n.size();
    int cnt = 0, ans = 0;
    for (int i = sz - 1; i >= 0; i--) {
      if (n[i] != '0') {
        ans++;
      }
    }
    // 00
    for (int i = sz - 1; i >= 0; i--) {
      if (n[i] == '0') {
        cnt++;
      }
      if (cnt == 2) {
        ans = min(ans, sz - 2 - i);
        break;
      }
    }
    cnt = 0;
    // 25
    for (int i = sz - 1; i >= 0; i--) {
      if (cnt == 0 && n[i] == '5') {
        cnt++;
      }
      if (cnt == 1 && n[i] == '2') {
        cnt++;
      }
      if (cnt == 2) {
        ans = min(ans, sz - 2 - i);
        break;
      }
    }
    cnt = 0;
    // 50
    for (int i = sz - 1; i >= 0; i--) {
      if (cnt == 0 && n[i] == '0') {
        cnt++;
      }
      if (cnt == 1 && n[i] == '5') {
        cnt++;
      }
      if (cnt == 2) {
        ans = min(ans, sz - 2 - i);
        break;
      }
    }
    cnt = 0;
    // 75
    for (int i = sz - 1; i >= 0; i--) {
      if (cnt == 0 && n[i] == '5') {
        cnt++;
      }
      if (cnt == 1 && n[i] == '7') {
        cnt++;
      }
      if (cnt == 2) {
        ans = min(ans, sz - 2 - i);
        break;
      }
    }
    cout << ans << '\n';
  }
}