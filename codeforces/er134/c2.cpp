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
    for (int i = 0, j = 0; i < n; i++) {
      while (b[j] < a[i]) j++;
      cout << b[j] - a[i] << " ";
    }
    cout << "\n";
    for (int i = 0, j = 0; i < n; i++) {
      for (j = max(j, i + 1); j < n && a[j] <= b[j - 1];) j++;
      cout << b[j - 1] - a[i] << " ";
    }
    cout << "\n";
  }
}
