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
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> one(n), zero(n);
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        zero[i] = (s[i] == '0');
      } else {
        zero[i] = zero[i - 1] | (s[i] == '0');
      }
    }
    for (ll i = n - 1; i >= 0; i--) {
      if (i == n - 1) {
        one[i] = (s[i] == '1');
      } else {
        one[i] = one[i + 1] | (s[i] == '1');
      }
    }
    ll real = 0;
    for (int i = 0; i < n; i++) {
      if ((i > 0 && zero[i - 1]) || (i < n - 1 && one[i + 1])) real++;
    }
    cout << n - real << "\n";
  }
}
