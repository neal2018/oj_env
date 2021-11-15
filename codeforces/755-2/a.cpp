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
    cout << u * u << " " << -v * v << '\n';
  }
}