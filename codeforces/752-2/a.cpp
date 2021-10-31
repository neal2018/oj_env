#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, a;
  cin >> T;
  while (T--) {
    cin >> n;
    ll maxi = 0;
    for (ll i = 1; i <= n; i++) {
      cin >> a;
      maxi = max(maxi, a - i);
    }
    cout << maxi << '\n';
  }
}