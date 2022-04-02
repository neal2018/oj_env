#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  long double p;
  cin >> p;
  long double t = 1e18;
  int res = -1;
  int f = 1;
  for (int i = 2; i <= 16; i++) {
    long double pp = pow(1 - p, i);
    long double tt = pp / i + (1 - pp);
    if (res == -1 || tt < t) {
      res = i;
      t = tt;
    }
    if (tt < i) f = 0;
    cout << i << " " << tt << "\n";
  }
  cout << (f ? 1 : res) << "\n";
}
