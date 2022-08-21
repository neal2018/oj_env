#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    int one = 0;
    for (auto& x : a) one += int(count(x.begin(), x.end(), '1'));
    auto minus = [&] {
      int need = 2;
      for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
          int cnt =
              (a[i][j] - '0') + (a[i][j + 1] - '0') + (a[i + 1][j] - '0') + (a[i + 1][j + 1] - '0');
          if (cnt < 3) return 0;
          if (cnt == 3) need = 1;
        }
      }
      return need;
    }();
    cout << one - minus << "\n";
  }
}
