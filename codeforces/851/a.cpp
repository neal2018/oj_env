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
    int two = int(count(a.begin(), a.end(), 2));
    if (two % 2 == 1) {
      cout << "-1\n";
      continue;
    }
    [&] {
      int cur = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] == 2) cur++;
        if (cur == two / 2) {
          cout << i + 1 << "\n";
          return;
        }
      }
    }();
  }
}
