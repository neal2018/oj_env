#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  [&] {
    for (int i = 1; i < n; i++) {
      if (a[i] - a[i - 1] <= d) {
        cout << a[i] << "\n";
        return;
      }
    }
    cout << "-1\n";
  }();
}
