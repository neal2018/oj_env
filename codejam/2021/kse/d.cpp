#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define LOCAL

int main() {
#ifdef LOCAL
  ifstream cin("/Users/neallai/Projects/oj_env/input.txt");
  ofstream cout("/Users/neallai/Projects/oj_env/output.txt");
#endif  // LOCAL
  ll T, n;
  cin >> T;
  for (ll TT = 1; TT <= T; TT++) {
    cout << "Case #" << TT << ": ";
    cin >> n;
    cout << fixed << setprecision(10);
    if (n < 5 * 1e8) {
      long double fn = 0;
      long double sum = 0;
      for (long double i = 1; i <= n; i++) {
        fn = 1 + (sum) / i;
        sum = sum + fn;
      }
      cout << fn << endl;
    } else {
      long double C = 0.57721566490153286060651209;
      cout << log((long double)n) + C << endl;
    }
  }
}
