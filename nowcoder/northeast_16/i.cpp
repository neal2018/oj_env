#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  // double res = 0, sum = 0;
  // int LIMIT = n;
  int CUT = 1e8;
  // {
  //   double res = 0, sum = 0;
  //   for (int i = 2; i <= LIMIT; i++) {
  //     res = sum / (i - 1) + double(i) / (i - 1);
  //     sum += res;
  //     // if (i % CUT == 1) {
  //     //   cout << i << " " << res << " " << sum << "\n";
  //     // }
  //   }
  //   cout << res << "\n";
  // }
  vector<tuple<int, double, double>> memo = {
      {1, 0, 0},
      {100000001, 19.99789641385040539490, 1899789660.38293695449829101562},
      {200000001, 20.69104359191184627775, 3938208738.07341241836547851562},
      {300000001, 21.09650869918695548222, 6028952629.85259532928466796875},
      {400000001, 21.38419077122239997379, 8153676328.87315082550048828125},
      {500000001, 21.60733432228633077443, 10303667181.75049972534179687500},
      {600000001, 21.78965587891396893383, 12473793548.13803672790527343750},
      {700000001, 21.94380655862138596035, 14660664611.97877502441406250000},
      {800000001, 22.07733795115682084997, 16861870382.00279426574707031250},
      {900000001, 22.19512098674403333121, 19075608909.26475143432617187500},
  };
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  for (auto [start, res, sum] : memo) {
    if (n - start < CUT) {
      for (int i = start + 1; i <= n; i++) {
        res = sum / (i - 1) + double(i) / (i - 1);
        sum += res;
      }
      cout << res << "\n";
      return 0;
    }
  }
}
