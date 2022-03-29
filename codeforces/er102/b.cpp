#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    auto get_unit = [&](string& ss) {
      ll n = ss.size();
      for (int i = 0; i < n; i++) {
        if (n % (i + 1) == 0) {
          string unit = ss.substr(0, i + 1), tmp;
          for (int j = 0; j < n / (i + 1); j++) tmp += unit;
          if (tmp == ss) return unit;
        }
      }
      return s;
    };
    string ss = get_unit(s), tt = get_unit(t);
    if (ss == tt) {
      ll sz = lcm(s.size() / ss.size(), t.size() / tt.size());
      string res;
      for (int i = 0; i < sz; i++) res += ss;
      cout << res << "\n";
    } else {
      cout << "-1\n";
    }
  }
}
