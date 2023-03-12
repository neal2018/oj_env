#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll l, r, b, k;
  cin >> l >> r >> b >> k;
  if (l >= b) {
    cout << (l + b - 1) / b * b * k << "\n";
  } else {
    cout << b * k << "\n";
  }
}
