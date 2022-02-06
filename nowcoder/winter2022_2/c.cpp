#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int cur, a, b;
  cin >> cur >> a >> b;
  string s;
  cin >> s;
  int n = (int)s.size();
  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0')
      cur += b;
    else {
      if (cur >= a)
        cnt++, cur -= a;
      else
        cur += b;
    }
  }
  cout << cnt << "\n";
}