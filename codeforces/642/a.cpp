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
    if (n == 1) {
      cout << "0\n";
    } else if (n == 2) {
      cout << m << "\n";
    } else {
      cout << 2 * m << "\n";
    }
  }
}
