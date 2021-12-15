#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (int n; T--;) {
    cin >> n;
    int cur = 1;
    int pre = 1, die = 0;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      if (!pre && !x) die = 1;
      if (x && pre && i > 0) {
        cur += 5;
      } else if (x) {
        cur++;
      }
      pre = x;
    }
    if (die) {
      cout << -1 << '\n';
    } else {
      cout << cur << '\n';
    }
  }
}