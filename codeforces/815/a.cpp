#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll t = lcm(b, d);
    a = a * (t / b);
    c = c * (t / d);
    if (a == c) {
      cout << "0\n";
    } else if (a == 0 || c == 0 || a % c == 0 || c % a == 0) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }
}
