#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    for (auto& x : a) {
      if (x == 1) x++;
    }
    for (int i = 0; i < n - 1; i++) {
      if (a[i + 1] % a[i] == 0) a[i + 1]++;
      assert(a[i + 1] % a[i]);
    }
    for (auto& x : a) cout << x << " ";
    cout << "\n";
  }
}
