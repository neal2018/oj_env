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
    ll n;
    string s;
    cin >> n >> s;
    ll res = 0, cnt = 0, rolling = 0;
    char sign = s[0];
    for (int i = 0; i < n; i += 2) {
      if (s[i] != s[i + 1]) {
        res++;
      } else {
        if (rolling && sign != s[i]) {
          rolling = 0, cnt++;
        }
        sign = s[i];
        rolling++;
      }
    }
    if (rolling) cnt++;
    if (cnt == 0) cnt = 1;
    cout << res << " " << cnt << "\n";
  }
}
