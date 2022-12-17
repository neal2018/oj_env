#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    ll zero = count(s.begin(), s.end(), '0');
    ll res = zero * (n - zero);
    for (int i = 0, j = 0; i < n; i = j) {
      for (j = i; j < n && s[i] == s[j];) j++;
      res = max(res, ll(j - i) * (j - i));
    }
    cout << res << "\n";
  }
}
