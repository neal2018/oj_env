#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    if (k == 1) {
      cout << (n - 1) / 2 << "\n";
    } else {
      int res = 0;
      for (auto i : views::iota(1, n - 1)) {
        if (a[i] > a[i - 1] + a[i + 1]) res++;
      }
      cout << res << "\n";
    }
  }
}
