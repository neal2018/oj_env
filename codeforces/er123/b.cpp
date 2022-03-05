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
    if (n == 3) {
      cout << "3 2 1\n1 3 2\n3 1 2\n";
    } else {
      for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
          cout << (j + i) % n + 1 << " ";
        }
        cout << "\n";
      }
    }
  }
}
