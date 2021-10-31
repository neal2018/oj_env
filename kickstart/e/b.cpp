#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LOCAL

int main() {
#ifdef LOCAL
  ifstream cin("/Users/neallai/Projects/oj_env/input.txt");
  ofstream cout("/Users/neallai/Projects/oj_env/output.txt");
#endif  // LOCAL
  ll T, r, c, k, r1, r2, c1, c2;
  cin >> T;
  for (ll TT = 1; TT <= T; TT++) {
    cout << "Case #" << TT << ": ";
    cin >> r >> c >> k >> r1 >> c1 >> r2 >> c2;
    r--, c--, r1--, r2--, c1--, c2--;
    ll rr = r2 - r1 + 1, cc = c2 - c1 + 1;
    ll needed = (rr + k - 1) / k * (cc - 1) + (cc + k - 1) / k * (rr - 1);
    ll f = 1e18;
    // left up
    // left
    f = min(f, (r1 + rr + k - 1) / k + (rr + k - 1) / k + (cc + k - 1) / k * 2);
    // up
    f = min(f, (rr + k - 1) / k * 2 + (c1 + cc + k - 1) / k + (cc + k - 1) / k);
    // right up
    // right
    f = min(f, (r - r2 + rr + k - 1) / k + (rr + k - 1) / k + (cc + k - 1) / k * 2);
    f = min(f, (rr + k - 1) / k * 2 + (c - c2 + cc + k - 1) / k + (cc + k - 1) / k);
    ll row_save = (r1 == 0) + (r2 == r);
    ll col_save = (c1 == 0) + (c2 == c);
    // cout << f << endl;
    // cout << "Saved: " << row_save + col_save << endl;
    // cout << r << " " << c << " " << r1 << " " << r2 << " " << c1 << " " << c2 << endl;
    // cout << row_save << " " << col_save << endl;
    if (row_save + col_save >= 1) {
      f = min(f, (rr + k - 1) / k * (2 - col_save) + (cc + k - 1) / k * (2 - row_save));
      // cout << f << endl;
    }
    cout << f + needed << endl;
  }
}
