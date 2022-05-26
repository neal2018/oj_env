#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  auto func = [&]() {
    ll n, U, R, D, L;
    cin >> n >> U >> R >> D >> L;
    for (int i = 0; i < (1 << 4); i++) {
      int a[4]{};
      if (i & 1) a[0] = 1;
      if (i & 2) a[1] = 1;
      if (i & 4) a[2] = 1;
      if (i & 8) a[3] = 1;
      ll u = U - (a[0] + a[1]);
      ll d = D - (a[2] + a[3]);
      ll l = L - (a[0] + a[2]);
      ll r = R - (a[1] + a[3]);
      if (0 <= u && u <= n - 2 && 0 <= d && d <= n - 2 && 0 <= l && l <= n - 2 && 0 <= r &&
          r <= n - 2) {
        return true;
      }
    }
    return false;
  };
  int T;
  cin >> T;
  while (T--) cout << (func() ? "YES\n" : "NO\n");
}
