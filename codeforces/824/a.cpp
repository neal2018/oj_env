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
    int L = n - 4;
    int res = 0;
    for (int i = max(1, L / 3 - 10); i <= min(L - 1, L / 3 + 10); i++) {
      int cur = min({abs(i - 1), abs(L - i - 1), abs(L - 2 * i)});
      res = max(res, cur);
    }
    cout << res << "\n";
  }
}
