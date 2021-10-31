#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  string s;
  while (T--) {
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (auto& x : s) {
      if (x == 'A') a++;
      if (x == 'B') b++;
      if (x == 'C') c++;
    }
    if (b == a + c)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}