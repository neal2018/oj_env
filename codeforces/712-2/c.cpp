#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
const ll MOD = 1e9 + 7;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  string s, t1, t2;
  cin >> T;
  while (T--) {
    cin >> n >> s;
    t1 = t2 = s;
    ll cnt = count(s.begin(), s.end(), '1');
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        if (cnt > 0) {
          t1[i] = t2[i] = '(';
          cnt -= 2;
        } else {
          t1[i] = t2[i] = ')';
        }
      }
    }
    int rolling1 = 0, rolling2 = 0, can = 1, pre = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        t1[i] = (pre == 0 ? '(' : ')');
        pre = !pre;
        t2[i] = (t1[i] == '(' ? ')' : '(');
      }
      rolling1 += (t1[i] == '(' ? 1 : -1);
      rolling2 += (t2[i] == '(' ? 1 : -1);
      if (rolling2 < 0 || rolling2 < 0) {
        can = 0;
        break;
      }
    }
    if (can && rolling1 == 0 && rolling2 == 0) {
      cout << "YES\n" << t1 << '\n' << t2 << '\n';
    } else {
      cout << "NO\n";
    }
  }
}