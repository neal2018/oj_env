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
    if (n == 1) {
      cout << "1\n";
    } else if (n % 2) {
      cout << "-1\n";
    } else {
      vector<int> target(n);
      for (int i = 0; i < n; i += 2) {
        target[i] = i / 2 + 1, target[i + 1] = n + 1 - target[i];
      }
      cout << n << " ";
      for (int i = 1; i < n; i++) {
        cout << (target[i] - target[i - 1] + n) % n << " ";
      }
      cout << "\n";
    }
  }
}
