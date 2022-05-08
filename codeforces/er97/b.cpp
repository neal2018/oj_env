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
    ll a = 0, b = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) {
        (s[i] == '0' ? a : b)++;
      }
    }
    cout << max(a, b) << "\n";
  }
}
