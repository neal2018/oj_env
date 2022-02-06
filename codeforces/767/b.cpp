#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    set<string> st_real, st, st3;
    int f = 0;
    for (int _ = 0; _ < n; _++) {
      cin >> s;
      if (f) continue;
      if (s.size() == 1) {
        f = 1;
      } else if (s.size() == 2) {
        if (s[0] == s[1]) f = 1;
        auto t = string(1, s[1]) + string(1, s[0]);
        if (st_real.count(t) || st.count(t)) f = 1;
        st_real.insert(s);
      } else {
        if (s[0] == s[2]) f = 1;
        auto t = string(1, s[2]) + string(1, s[1]);
        if (st_real.count(t)) f = 1;
        auto tt = string(1, s[0]) + string(1, s[1]);
        st.insert(tt);
        auto t3 = string(1, s[2]) + string(1, s[1]) + string(1, s[0]);
        if (st3.count(t3)) f = 1;
        st3.insert(s);
      }
    }
    cout << (f ? "YES\n" : "NO\n");
  }
}