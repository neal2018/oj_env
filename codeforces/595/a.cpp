#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

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
    int res = 1;
    for (int i = 0; i < n - 1; i++) {
      if (a[i + 1] == a[i] + 1) res = 2;
    }
    cout << res << "\n";
  }
}
