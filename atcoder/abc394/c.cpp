#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  std::string res;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'W') {
      int j = i;
      while (j < s.size() && s[j] == 'W') {
        j++;
      }
      if (j != s.size() && s[j] == 'A') {
        res += 'A';
        for (int _ = i; _ < j; _++) {
          res += 'C';
        }
        i = j;
      } else {
        for (int _ = i; _ < j; _++) {
          res += 'W';
        }
        i = j - 1;
      }
    } else {
      res += s[i];
    }
  }
  std::cout << res << "\n";
}
