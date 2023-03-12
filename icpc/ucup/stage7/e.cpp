#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int l, r;
    cin >> l >> r;
    vector<int> res;
    if ((r - l + 1) % 2 == 0) {
      for (int i = l; i < r; i += 2) {
        cout << i + 1 << " " << i << " ";
      }
      cout << "\n";
    } else if (l == r && l == 1) {
      cout << "1\n";
    } else {
      if (l % 2 == 0 || l == r) {
        cout << "-1\n";
      } else {
        cout << l + 2 << " " << l << " " << l + 1 << " ";
        for (int i = l + 3; i < r; i += 2) {
          cout << i + 1 << " " << i << " ";
        }
        cout << "\n";
      }
    }
  }
}
