#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, a, b, c;
  cin >> T;
  while (T--) {
    cin >> a >> b >> c;
    if ((a + b + c) % 3 == 0) {
      cout << 0 << '\n';
    } else {
      cout << 1 << '\n';
    }
  }
}