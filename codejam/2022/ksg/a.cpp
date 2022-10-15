#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int m, n, k;
    cin >> m >> n >> k, k--;
    vector<int> a(n), maxi(n);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int x;
        cin >> x;
        maxi[j] = max(maxi[j], x);
        if (i == k) a[j] = x;
      }
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
      res += maxi[i] - a[i];
    }
    cout << res << "\n";
  }
}
