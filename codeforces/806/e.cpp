#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    int res = 0;
    for (auto i : views::iota(0, (n + 1) / 2)) {
      for (auto j : views::iota(0, n / 2)) {
        int one = (a[i][j] == '1') + (a[j][n - 1 - i] == '1') + (a[n - 1 - i][n - 1 - j] == '1') +
                  (a[n - 1 - j][i] == '1');
        res += min(one, 4 - one);
      }
    }
    cout << res << "\n";
  }
}
