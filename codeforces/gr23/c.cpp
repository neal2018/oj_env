#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<pair<int, int>> diff;
    for (int i = 1; i < n; i++) {
      if (a[i] < a[i - 1]) diff.push_back({a[i - 1] - a[i], i});
    }
    sort(diff.begin(), diff.end(), greater());
    vector<int> res(n, n - 1);
    int t = n - 1;
    for (auto& [val, i] : diff) {
      res[t] = i, t--;
    }
    for (auto& x : res) cout << x + 1 << " ";
    cout << "\n";
  }
}
