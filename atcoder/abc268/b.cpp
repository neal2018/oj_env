#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  if (t.size() < s.size()) {
    cout << "No\n";
    return 0;
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != t[i]) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}
