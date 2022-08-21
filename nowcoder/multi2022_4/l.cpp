#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    ld a;
    cin >> n >> a >> k;
    if (n == 4) {
      cout << "possible 4 ";
      for (int i = 0; i < k; i++) a /= 3;
      cout << a << "\n";
    } else if (n == 6 || n == 8) {
      cout << "possible ";
      function<pair<int, ld>(int, ld, int)> dfs = [&](int nn, ld aa, int kk) {
        if (kk == 0) return pair{nn, aa};
        if (nn == 6) {
          return dfs(8, aa / sqrt(2), kk - 1);
        }
        return dfs(6, aa * sqrt(2) / 3, kk - 1);
      };
      auto [nn, aa] = dfs(n, a, k);
      cout << nn << " " << aa << "\n";
    } else if (n == 12 || n == 20) {
      cout << "possible ";
      ld phi = (sqrt(5) + 1) / 2;
      function<pair<int, ld>(int, ld, int)> dfs = [&](int nn, ld aa, int kk) {
        if (kk == 0) return pair{nn, aa};
        if (nn == 12) {
          return dfs(20, aa * phi * phi / sqrt(5), kk - 1);
        }
        return dfs(12, aa * phi / 3, kk - 1);
      };
      auto [nn, aa] = dfs(n, a, k);
      cout << nn << " " << aa << "\n";
    } else {
      cout << "impossible\n";
    }
  }
}
