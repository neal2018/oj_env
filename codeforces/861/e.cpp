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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> res(n - 1, 2);
    vector<int> maxi(n + 1, 1), exact(n + 1, -1);
    maxi[n] = 0, exact[n] = 0;
    if (a[n - 1] == 0) exact[n - 1] = 1;
    int cur_maxi = exact[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if (i + a[i] + 1 <= n && exact[i + a[i] + 1] != -1) {
        exact[i] = 1 + exact[i + a[i] + 1];
      }
      if (i + a[i] + 1 <= n) {
        maxi[i] = max(maxi[i], maxi[i + a[i] + 1] + 1);
      }
      maxi[i] = max(maxi[i], cur_maxi + 1);
      cur_maxi = max(cur_maxi, exact[i]);
      if (exact[i + 1] != -1 && a[i] == exact[i + 1]) {
        res[i] = 0;
      } else if (exact[i + 1] != -1) {
        res[i] = 1;
      } else if (a[i] <= maxi[i + 1]) {
        res[i] = 1;
      }
    }
    for (auto& x : res) {
      cout << x << " ";
    }
    cout << "\n";
  }
}
