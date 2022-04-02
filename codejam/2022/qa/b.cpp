#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e18;
constexpr ll need = 1e6;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_num = 1; case_num <= T; case_num++) {
    cout << "Case #" << case_num << ": ";
    ll a = inf, b = inf, c = inf, d = inf;
    for (ll i = 0, aa, bb, cc, dd; i < 3; i++) {
      cin >> aa >> bb >> cc >> dd;
      a = min(a, aa), b = min(b, bb), c = min(c, cc), d = min(d, dd);
    }
    if (a + b + c + d < need) {
      cout << "IMPOSSIBLE\n";
    } else {
      ll cur = need;
      for (auto x : {a, b, c, d}) {
        ll minus = min(a, cur);
        cout << minus << " ";
        cur -= minus;
      }
      cout << "\n";
    }
  }
}