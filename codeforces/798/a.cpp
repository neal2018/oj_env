#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    int n, m, k;
    cin >> n >> m >> k >> s >> t;
    string c;
    sort(s.begin(), s.end()), sort(t.begin(), t.end());
    int i = 0, j = 0, streaking = 0, pre = -1;
    while (i < n && j < m) {
      int cur = (s[i] < t[j] ? 0 : 1);
      if (streaking == k) {
        cur = pre ^ 0 ^ 1;
      }
      if (cur == 0) {
        c += s[i], i++;
      } else {
        c += t[j], j++;
      }
      if (pre == cur) {
        streaking += 1;
      } else {
        streaking = 1;
      }
      pre = cur;
    }
    cout << c << "\n";
  }
}
