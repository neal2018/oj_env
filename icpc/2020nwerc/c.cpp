#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, k, d, s;
  cin >> n >> k >> d >> s;
  auto res = (long double)(n * d - k * s) / (n - k);
  if ((n * d - k * s) < 0 || (n * d - k * s) > 100 * (n - k)) {
    cout << "impossible\n";
  } else {
    cout << res << "\n";
  }
}
