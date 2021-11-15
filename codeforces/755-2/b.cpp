#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, u, v;
  cin >> T;
  while (T--) {
    cin >> u >> v;
    ll total = u * v;
    cout << total / 3 + (total % 3 != 0) << '\n';
  }
}