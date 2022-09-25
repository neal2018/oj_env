#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    ll res = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j += i) {
        if (s[j - 1] == '0') {
          res += i;
          s[j - 1] = '2';
        } else if (s[j - 1] == '1') {
          break;
        }
      }
    }
    cout << res << "\n";
  }
}
