#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
const ll MOD = 1e9 + 7;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    map<int, int> a, b;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      a[x]++;
    }
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      b[x]++;
    }
    int f = 1;
    for (int i = 100; i >= -100 && f; i--) {
      if (a[i] > b[i]) {
        f = 0;
      } else if (a[i] < b[i]) {
        if (i == -100 || a[i - 1] + a[i] < b[i]) {
          f = 0;
        } else {
          int need = b[i] - a[i];
          a[i - 1] -= need;
        }
      }
    }
    cout << (f ? "YES\n" : "NO\n");
  }
}