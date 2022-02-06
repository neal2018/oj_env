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
      for (int i = 0; i < n; i++) {
        cout << i + 1 << "\n";
      }
      continue;
    }
    if (n % 2) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    vector a(n, vector<int>(k + 1));
    int cur = 1;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n; j++) {
        a[j][i] = cur++;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++) {
        cout << a[i][j] << " ";
      }
      cout << "\n";
    }
  }
}