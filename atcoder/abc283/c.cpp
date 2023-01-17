#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  int res = 0;
  for (int i = 0, j; i < s.size(); i = j) {
    for (j = i; j < s.size() && s[i] == s[j];) j++;
    if (s[i] != '0') {
      res += j - i;
    } else {
      res += (j - i + 1) / 2;
    }
  }
  cout << res << "\n";
}
