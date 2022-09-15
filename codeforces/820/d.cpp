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
    for (int t; auto& x : a) cin >> t, x = t - x;
    sort(a.begin(), a.end());
    int res = 0;
    for (int i = 0, j = n - 1; i < j;) {
      while (a[i] + a[j] < 0 && i < j) i++;
      if (i < j) {
        res++;
        i++, j--;
      }
    }
    cout << res << "\n";
  }
}
