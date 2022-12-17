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
    if (n % 2 == 0) {
      if ([&] {
            for (int i = 0; i < n; i++) {
              if (a[i] != a[i % 2]) return false;
            }
            return true;
          }()) {
        cout << (n - 2) / 2 + 2 << "\n";
        continue;
      }
    }
    cout << n << "\n";
  }
}
