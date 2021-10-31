#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, n, m;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    ll x = (m) / 2 + 1;
    if (x >= n) {
      cout << (m - x) << endl;
    } else {
      cout << (m - n) << endl;
    }
  }
}