#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, a, b;
  cin >> T;
  while (T--) {
    cin >> n >> a >> b;
    vector<ll> left{a}, right{b}, seen(n + 1);
    seen[a] = 1, seen[b] = 1;
    for (ll i = 1; i <= n; i++) {
      if (i == a || i == b) continue;
      if (i < a) {
        right.push_back(i), seen[i] = 1;
      }
      if (i > b) {
        left.push_back(i), seen[i] = 1;
      }
    }
    if (left.size() > n / 2 || right.size() > n / 2) {
      cout << -1 << '\n';
    } else {
      for (ll i = 1; i <= n; i++) {
        if (seen[i] == 0) {
          if (left.size() < right.size()) {
            left.push_back(i);
          } else {
            right.push_back(i);
          }
        }
      }
      for (auto& x : left) cout << x << " ";
      for (auto& x : right) cout << x << " ";
      cout << '\n';
    }
  }
}