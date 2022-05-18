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
    ll n, res = 0;
    string s;
    cin >> n >> s;
    for (int i = 0, j; i < n; i = j) {
      for (j = i; j < n && s[i] == s[j];) j++;
      if ((j - i) % 2 != 0) {
        res++;
        j--;
        s[j] = s[i] ^ '0' ^ '1';
      }
    }
    cout << res << "\n";
  }
}
