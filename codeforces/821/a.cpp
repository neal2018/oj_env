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
    ll res = 0;
    for (int i = 0; i < k; i++) {
      int cur = a[i];
      for (int j = i; j < n; j += k) {
        cur = max(cur, a[j]);
      }
      res += cur;
    }
    cout << res << "\n";
  }
}
