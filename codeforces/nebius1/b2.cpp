#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k, d, w;
    cin >> n >> k >> d >> w;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int res = 0;
    for (int i = 0; i < n;) {
      res++;
      int limit = a[i] + d + w;
      for (int j = 0; j < k && i < n && a[i] <= limit; j++) {
        i++;
      }
    }
    cout << res << "\n";
  }
}
