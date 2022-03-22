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
    string s;
    cin >> n >> s;
    int res = 0, i = 0, j = 0;
    while (i < n - 1) {
      if (s[i] == '(') {
        i += 2, res++;
      } else {
        for (j = i + 1; j < n && s[j] != ')';) j++;
        if (j == n) break;
        i = j + 1, res++;
      }
    }
    cout << res << " " << n - i << "\n";
  }
}
