#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t;
  for (auto& c : s) {
    if (c == 'A') {
      t += "BB";
    } else {
      t += c;
    }
  }
  ll sz = t.size();
  string res;
  for (int i = 0; i < sz; i++) {
    if (i < sz - 1 && t[i] == 'B' && t[i + 1] == 'B') {
      res += 'A', i++;
    } else {
      res += t[i];
    }
  }
  cout << res << "\n";
}
