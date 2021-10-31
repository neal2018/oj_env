#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  char c;
  cin >> T;
  auto solve = [&]() {
    cin >> n >> c;
    ll cnt = 0;
    vector<char> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i] != c) cnt++;
    }
    if (cnt == 0) {
      cout << 0 << '\n';
      return;
    }
    for (int i = n / 2; i < n; i++) {
      if (v[i] == c) {
        cout << 1 << '\n' << i + 1 << '\n';
        return;
      }
    }
    cout << 2 << '\n' << n << ' ' << n - 1 << '\n';
  };
  while (T--) {
    solve();
  }
}