#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    string res = s, sum = s;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        res[i] = '1';
      } else {
        if (s[i] == '0') {
          if (sum[i - 1] == '1') {
            res[i] = '0';

          } else {
            res[i] = '1';
          }
        } else {
          if (sum[i - 1] == '2') {
            res[i] = '0';
          } else {
            res[i] = '1';
          }
        }
      }
      sum[i] = res[i] + s[i] - '0';
    }
    cout << res << '\n';
  }
}