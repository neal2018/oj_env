#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    cin >> n >> k;
    if (k == 1) {
      cout << "YES\n";
      for (int i = 0; i < n * k; i++) cout << i + 1 << "\n";
    } else if (n % 2) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
          cout << n * j + i + 1 << " \n"[j == k - 1];
        }
      }
    }
  }
}
