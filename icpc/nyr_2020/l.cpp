#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  for (int c = 0; c < 26; c++) {
    char a = c + 'a';
    int i1 = -1, i2 = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == a) {
        if (i1 != -1 && i2 != -1) {
          cout << "NO\n";
          return 0;
        }
        if (i1 == -1) {
          i1 = i;
        } else {
          i2 = i;
          if ((i2 - i1) % 2 != 1) {
            cout << "NO\n";
            return 0;
          }
        }
      }
    }
  }
  cout << "YES\n";
}