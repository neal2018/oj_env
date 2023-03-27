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
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    [&] {
      for (int i = 0; i < n; i++) {
        if ((a[i] > a[n - 1] || b[i] > b[n - 1]) && (a[i] > b[n - 1] || b[i] > a[n - 1])) {
          cout << "No\n";
          return;
        }
      }
      cout << "Yes\n";
    }();
  }
}
