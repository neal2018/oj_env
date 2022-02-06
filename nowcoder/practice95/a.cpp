#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  ll T, n, m;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    ll x = 1, cnt = 0;
    while (x < n) {
      x *= (m + 1);
      cnt++;
    }
    cout << cnt << '\n';
  }
}