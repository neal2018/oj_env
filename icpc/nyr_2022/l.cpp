#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s, t;
  cin >> s;
  for (int i = 0; i < 7; i++) {
    cin >> t;
    string res = "YYYYY";
    // cout << t << "\n";
    for (int j = 0; j < 5; j++) {
      if (t[j] == s[j]) {
        res[j] = 'G';
      } else if (find(s.begin(), s.end(), t[j]) == s.end()) {
        res[j] = 'X';
      }
    }
    if (res == "GGGGG") {
      cout << "WINNER\n";
      return 0;
    } else if (i == 6) {
      cout << "LOSER\n";
    } else {
      cout << res << "\n";
    }
  }
}
