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
  int t = 0;
  while (t < n && s[t] == '0') t++;
  if (t == n) {
    cout << "0\n";
    return 0;
  }
  int tt = t;
  while (tt < n && s[tt] == '1') tt++;
  if (tt == n) {
    cout << s.substr(t) << "\n";
    return 0;
  }
  string res = s.substr(t);
  auto a = s.substr(t);
  for (int len = n - t; len >= n - tt; len--) {
    auto b = s.substr(t, len);
    auto cur = a;
    for (int j = 0; j < b.size(); j++) {
      if (b[int(b.size()) - j - 1] == '1') {
        cur[int(cur.size()) - j - 1] = '1';
      }
    }
    res = max(res, cur);
  }
  cout << res << "\n";
}
