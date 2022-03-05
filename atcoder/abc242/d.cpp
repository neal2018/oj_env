#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  ll q;
  cin >> q;
  while (q--) {
    function<int(ll, ll)> dfs = [&](ll k, ll x) -> int {
      if (x == 0) {
        return s[k] - 'A';
      }
      if (k == 0) {
        return (s[0] - 'A' + int(x % 3ll)) % 3;
      }
      if (k % 2 == 0) {
        return (dfs(k / 2, x - 1) + 1) % 3;
      } else {
        return (dfs(k / 2, x - 1) + 2) % 3;
      }
    };
    ll t, k;
    cin >> t >> k, k--;
    ll c = dfs(k, t);
    cout << char(c + 'A') << "\n";
  }
}
