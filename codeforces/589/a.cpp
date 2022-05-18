#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll l, r;
  cin >> l >> r;
  for (int i = l; i <= r; i++) {
    string s = to_string(i);
    ll n = s.size();
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    if (n == s.size()) {
      cout << i << "\n";
      return 0;
    }
  }
  cout << "-1\n";
}
