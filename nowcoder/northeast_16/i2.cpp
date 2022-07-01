#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  if (n < 1000000) {
    ld res = 1;
    for (int i = 1; i <= n - 1; i++) res += ld(1.0) / i;
    cout << res << "\n";
  } else {
    cout << log(n - 1) + 1 + 0.577215664901532860606 << "\n";
  }
}
