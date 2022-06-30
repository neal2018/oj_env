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
    int n, res = 0;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    for (int i = 0; i < n;) {
      if (a[i] == 0) {
        i++;
      } else {
        int j = i;
        while (j < n && a[j] != 0) j++;
        i = j, res++;
      }
    }
    cout << min(res, 2) << "\n";
  }
}
