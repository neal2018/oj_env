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
    cout << ([&] {
      for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
          if (a[i] > b[i] || b[i] > b[(i + 1) % n] + 1) return false;
        }
      }
      return true;
    }()
                 ? "YES\n"
                 : "NO\n");
  }
}
