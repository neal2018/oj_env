#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  cout << fixed << setprecision(10);
  for (; T--;) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll x = 0, y = 0;
    ll dis = 0;
    for (auto& c : s) {
      if (c == 'U') {
        x++;
      } else if (c == 'D') {
        x--;
      } else if (c == 'L') {
        y++;
      } else {
        y--;
      }
      ll d = x * x + y * y;
      dis = max(dis, d);
    }
    cout << sqrt(dis) << "\n";
  }
}