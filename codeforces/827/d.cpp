#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAX = 1001;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    array<int, MAX> a = {};
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      a[x] = i + 1;
    }
    int res = -1;
    for (int i = 1; i < MAX; i++) {
      for (int j = 1; j < MAX; j++) {
        if (a[i] && a[j] && gcd(i, j) == 1) {
          res = max(res, a[i] + a[j]);
        }
      }
    }
    cout << res << "\n";
  }
}
