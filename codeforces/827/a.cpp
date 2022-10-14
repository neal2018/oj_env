#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c == 2 * max({a, b, c})) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
