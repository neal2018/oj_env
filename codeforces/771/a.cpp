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
    int index = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] != i + 1) {
        index = i;
        break;
      }
    }
    if (index != -1) {
      auto it = find(a.begin(), a.end(), index + 1);
      reverse(a.begin() + index, it + 1);
    }
    for (auto& x : a) cout << x << " ";
    cout << "\n";
  }
}
