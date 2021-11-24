#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n, l, r, maxi = -1e9, mini = 1e9;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    maxi = max(maxi, l);
    mini = min(mini, r);
    if (maxi < mini) {
      cout << 0 << '\n';
    } else {
      cout << (maxi - mini + 1) / 2 << '\n';
    }
  }
}