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
    int l = 0;
    for (int r = 0; r < n; r++) {
      while (l < r && a[l] < r - l + 1) l++;
      cout << r - l + 1 << " ";
    }
    cout << "\n";
  }
}
