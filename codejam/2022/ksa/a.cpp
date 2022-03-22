#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    string s, t;
    cin >> s >> t;
    ll n = s.size(), m = t.size();
    ll i = 0, j = 0;
    while (i < n && j < m) {
      if (s[i] == t[j]) {
        i++, j++;
      } else {
        j++;
      }
    }
    if (i == n) {
      cout << "Case #" << case_no << ": " << m - n << "\n";
    } else {
      cout << "Case #" << case_no << ": IMPOSSIBLE\n";
    }
  }
}
