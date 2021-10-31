#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  string s1, s2;
  while (T--) {
    cin >> n;
    int s[n][5];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> s[i][j];
      }
    }
    int can = 0;
    for (int i = 0; i < 5; i++) {
      for (int j = i + 1; j < 5; j++) {
        int both = 0, only_i = 0, only_j = 0;
        for (int k = 0; k < n; k++) {
          if (s[k][i] && s[k][j]) {
            both++;
          } else if (s[k][i]) {
            only_i++;
          } else if (s[k][j]) {
            only_j++;
          }
        }
        int h = n / 2;
        if (only_i <= h && only_j <= h && (h - only_j + h - only_i) == both) {
          can = 1;
          // cout << i << " " << j << " " << both<<" "<<only_i<<" "<<only_j<<endl;
          break;
        }
      }
      if (can == 1) break;
    }
    cout << (can ? "YES\n" : "NO\n");
  }
}