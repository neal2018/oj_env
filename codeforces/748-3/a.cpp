#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, a, b, c;
  cin >> T;
  while (T--) {
    cin >> a >> b >> c;
    ll maxi = max({a, b, c});
    int cnt = 0;
    if (a == maxi) cnt++;
    if (b == maxi) cnt++;
    if (c == maxi) cnt++;
    if (cnt == 1) {
      if (a != maxi) a--;
      if (b != maxi) b--;
      if (c != maxi) c--;
      cout << maxi - a << ' ' << maxi - b << ' ' << maxi - c << '\n';
    } else {
      cout << maxi - a + 1 << ' ' << maxi - b + 1 << ' ' << maxi - c + 1 << '\n';
    }
  }
}