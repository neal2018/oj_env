#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  string s;
  cin >> s;
  ll n = s.size();
  ll cnt = count(s.begin(), s.end(), s[0]);
  if (cnt == n || cnt == n - 1) {
    cout << "Impossible\n";
    return 0;
  }
  function<int(ll)> solve = [&](ll len) {
    if (len & 1) return 2;
    if (s.substr(0, len / 2) != s.substr(len / 2, len / 2)) return 1;
    return solve(len / 2);
  };
  cout << solve(n) << "\n";
}
