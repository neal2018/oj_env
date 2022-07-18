#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, t;
    cin >> n >> t;
    vector<int> a(2 * n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    cout << ([&] {
      for (int i = 0; i < n; i++) {
        if (a[i] + t > a[i + n]) return false;
      }
      return true;
    }()
                 ? "YES\n"
                 : "NO\n");
  }
}
