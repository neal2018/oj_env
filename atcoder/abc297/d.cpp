#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll a, b;
  cin >> a >> b;
  ll res = 0;
  while (a != b) {
    if (a > b) {
      res += a / b;
      a = a % b;
      if (a == 0) {
        a = b;
        res--;
      }
    } else {
      res += b / a;
      b = b % a;
      if (b == 0) {
        b = a;
        res--;
      }
    }
  }
  cout << res << "\n";
}
