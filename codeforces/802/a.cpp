#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n >> m;
    cout << ((1 + m) * m / 2 - m + (1 + n) * n / 2 * m) << "\n";
  }
}
