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
    if (a == vector(n, a[0])) {
      cout << "1\n";
      continue;
    }
    int res = 0;
    for (int i = 0, j = 0; i < n; i = j - 1) {
      if (i == n - 1) {
        res++;
        break;
      }
      for (j = i; j < n && a[i] == a[j];) j++;
      if (a[j - 1] > a[j]) {
        for (; j < n && a[j - 1] >= a[j];) j++;
      } else {
        for (; j < n && a[j - 1] <= a[j];) j++;
      }
      res++;
    }
    cout << res << "\n";
  }
}
