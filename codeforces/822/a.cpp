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
    sort(a.begin(), a.end());
    int res = 1e9;
    for (int i = 1; i < n - 1; i++) {
      res = min(res, (a[i] - a[i - 1]) + (a[i + 1] - a[i]));
    }
    cout << res << "\n";
  }
}
