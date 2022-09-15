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
    int res = 0;
    res = max(res, *max_element(a.begin(), a.end()) - a[0]);
    res = max(res, a.back() - *min_element(a.begin(), a.end()));
    for (int i = 0; i < n - 1; i++) {
      res = max(res, a[i] - a[i + 1]);
    }
    cout << res << "\n";
  }
}
