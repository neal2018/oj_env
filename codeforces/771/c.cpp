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
    int res = 0, maxi=0;
    for (int i = 0; i < n; i++) {
      maxi = max(maxi, a[i]);
      if (maxi == i + 1) res++;
    }
    cout << res << "\n";
  }
}
