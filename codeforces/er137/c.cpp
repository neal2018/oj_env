#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll res = 0;
    for (int i = 0, j = 0; i < n; i = j) {
      for (j = i; j < n && s[i] == s[j];) j++;
      if (s[i] == '0') continue;
      res += accumulate(a.begin() + i, a.begin() + j, 0ll);
      if (i != 0) {
        ll gain = 0;
        ll maxi = 0;
        for (int k = i; k < j; k++) {
          gain += a[k - 1] - a[k];
          maxi = max(maxi, gain);
        }
        res += maxi;
      }
    }
    cout << res << "\n";
  }
}
