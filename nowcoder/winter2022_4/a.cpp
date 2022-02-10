#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  ll res = 0, cnt = 0, pre = 0;
  for (int l = 0, r = 0; r < n; r++) {
    if (s[r] == 'P') {
      l = r + 1, cnt = 0, pre = r + 1;
    } else {
      if (s[r] == 'R') {
        cnt++;
      }
      int good = (cnt >= k);
      while (cnt >= k) {
        if (s[l] == 'R') cnt--;
        l++;
      }
      if (good) {
        cnt++, l--;
        res += l - pre + 1;
      }
    }
  }
  cout << res << "\n";
}
