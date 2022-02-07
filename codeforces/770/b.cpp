#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, x, y;
    string s;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (auto& xx : a) cin >> xx, x ^= xx;
    if (x % 2 == y % 2) {
      cout << "Alice\n";
    } else {
      cout << "Bob\n";
    }
  }
}
