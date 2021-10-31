#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, n;
  string s1, s2;
  cin >> T;
  while (T--) {
    cin >> n >> s1 >> s2;
    ll res = 0;
    for (int i = 0; i < n; i++) {
      if (s1[i] + s2[i] == '1' + '0') {
        res += 2;
      } else if (s1[i] + s2[i] == '0' + '0') {
        res++;
        if (i > 0 && (s1[i - 1] + s2[i - 1] == '1' + '1')) {
          res++;
          s1[i - 1] = '2', s2[i - 1] = '2';
        } else if (i < n && (s1[i + 1] + s2[i + 1] == '1' + '1')) {
          res++;
          s1[i + 1] = '2', s2[i + 1] = '2';
        }
      }
    }
    cout << res << '\n';
  }
}