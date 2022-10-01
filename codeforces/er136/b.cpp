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
    [&] {
      for (int i = 1; i < n; i++) {
        if (a[i - 1] - a[i] >= 0 && a[i] != 0) {
          cout << "-1\n";
          return;
        } else {
          a[i] += a[i - 1];
        }
      }
      for (auto& x : a) cout << x << " ";
      cout << "\n";
    }();
  }
}
