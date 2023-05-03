#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, t;
    cin >> n >> t;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    int res = -1, gain = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] + i <= t) {
        if (b[i] > gain) gain = b[i], res = i + 1;
      }
    }
    cout << res << "\n";
  }
}
