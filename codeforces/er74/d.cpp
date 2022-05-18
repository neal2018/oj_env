#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  string s;
  cin >> n >> s;
  ll res = (n - 1) * n / 2, pre = -1;
  for (int i = 0, j = 0; i < n; i = j) {
    for (j = i; j < n && s[i] == s[j];) j++;
    ll len = j - i;
    if (pre != -1) {
      res -= pre + len - 1;
    }
    pre = len;
  }
  cout << res << "\n";
}
