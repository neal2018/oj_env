#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int res = int(s.size());
    for (char c = 'a'; c <= 'z'; c++) {
      int cur = 0;
      for (int i = 0, j = 0; i < s.size(); i = j) {
        for (j = i; j < s.size() && (s[i] == c) == (s[j] == c);) j++;
        if (s[i] != c) {
          cur = max(cur, __lg(j - i) + 1);
        }
      }
      res = min(res, cur);
    }
    cout << res << "\n";
  }
}
