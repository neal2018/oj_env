#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_num = 1; case_num <= T; case_num++) {
    cout << "Case #" << case_num << ": ";
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    ll sum2 = accumulate(a.begin(), a.end(), 0ll, [&](ll x, ll y) { return x + y * y; });
    if (k == 1) {
      ll minus = sum2 - sum * sum;
      if (sum == 0) {
        if (sum2 != 0) {
          cout << "IMPOSSIBLE\n";
        } else {
          cout << 0 << "\n";
        }
      } else {
        if (minus % (2 * sum) != 0) {
          cout << "IMPOSSIBLE\n";
        } else {
          cout << minus / (2 * sum) << "\n";
        }
      }
    } else {
      ll t1 = 1 - sum, t2 = (sum * sum + sum2 - 2 * sum) / 2;
      cout << t1 << " " << t2 << "\n";
    }
  }
}
