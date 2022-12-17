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
    if (n & 1) {
      for (int i = 0; i < n; i++) {
        cout << "1 ";
      }
      cout << "\n";
    } else {
      for (int i = 0; i < n - 2; i++) {
        cout << "2 ";
      }
      cout << "1 3\n";
    }
  }
}
