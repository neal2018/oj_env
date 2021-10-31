#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
main() {
  int T, q, l, r;
  string s;
  cin >> T;
  while (T--) {
    cin >> s >> q;
    int n = s.size();
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
      cnt[i + 1] = cnt[i];
      if (s[i] == '[' || s[i] == ']') {
        i % 2 == 0 ? cnt[i + 1]++ : cnt[i + 1]--;
      }
    }
    while (q--) {
      cin >> l >> r;
      cout << abs(cnt[r] - cnt[l - 1]) << '\n';
    }
  }
}