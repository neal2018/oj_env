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
    ll sum = 0, res = 0;
    for (auto& c : s) {
      sum += (c - 'a') + 1ll;
    }
    if (n % 2 == 0) {
      res = sum;
    } else {
      res = max(sum - 2 * (s[0] - 'a' + 1ll), sum - 2 * (s.back() - 'a' + 1ll));
    }
    if (res > 0) {
      cout << "Alice " << res << "\n";
    } else {
      cout << "Bob " << -res << "\n";
    }
  }
}
