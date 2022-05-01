#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    set<char> all(s.begin(), s.end());
    ll n = s.size();
    int f = 1;
    for (auto& c : all) {
      int i = 0;
      while (s[i] != c) i++;
      for (int j; i < n && f; i = j) {
        for (j = i + 1; j < n && s[i] != s[j];) j++;
        if (j < n) {
          set<char> cur;
          for (int k = i; k < j; k++) {
            cur.insert(s[k]);
          }
          if (cur.size() != all.size()) {
            f = 0;
          }
        }
      }
      if (!f) break;
    }
    cout << (f ? "YES\n" : "NO\n");
  }
}
