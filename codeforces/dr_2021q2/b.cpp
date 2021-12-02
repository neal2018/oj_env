#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int even_cnt = 0;
    for (auto& x : a) {
      even_cnt += (x % 2 == 0);
    }
    if (n & 1) {
      if (n / 2 != even_cnt && n / 2 + 1 != even_cnt) {
        cout << -1 << endl;
      } else {
        ll res = 0;
        for (int i = 0, curr = (1 - even_cnt + n / 2); i < n; i++) {
          if (a[i] % 2 == 0) {
            res += abs(i - curr);
            curr += 2;
          }
        }
        cout << res << endl;
      }
    } else {
      if (n / 2 != even_cnt) {
        cout << -1 << endl;
      } else {
        ll temp = 1e18;
        for (int x : {0, 1}) {
          ll res = 0;
          for (int i = 0, curr = x; i < n; i++) {
            if (a[i] % 2 == 0) {
              res += abs(i - curr);
              curr += 2;
            }
          }
          temp = min(res, temp);
        }
        cout << temp << endl;
      }
    }
  }
}