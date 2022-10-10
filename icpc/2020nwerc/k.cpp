#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s, t;
  getline(cin, s);
  getline(cin, t);
  string res;
  int j = 0;
  for (int i = 0; i < s.size(); i++) {
    while (s[i] != t[j]) {
      res += t[j], j++;
    }
    j++;
  }
  while (j < t.size()) res += t[j], j++;
  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());
  cout << res << "\n";
}
