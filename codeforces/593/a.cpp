#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll a, b, c;
    cin >> a >> b >> c;
    ll take = min(b, c / 2);
    b -= take;
    cout << (min(a, b / 2) + take) * 3 << "\n";
  }
}
