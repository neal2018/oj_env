#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  getline(cin, s);
  int n = int(s.size());
  int index = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '-') {
      index = i;
      break;
    }
  }
  if (index != -1 && (1 < index && index <= 8 && (n - 1 - index) <= 24 && (n - 1 - index) >= 1)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
