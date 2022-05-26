#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll a, b;
    cin >> a >> b;
    tie(a, b) = minmax({a, b});
    ll diff = b - a;
    cout << diff << " ";
    if (!diff) {
      cout << 0 << "\n";
    } else {
      cout << min(diff - a % diff, a % diff) << "\n";
    }
  }
}
