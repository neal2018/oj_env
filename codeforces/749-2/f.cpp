#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  int n, k, res = 0;
  cin >> n >> k;
  vector c(n, vector<int>(n));
  for (int v = 1; v < n; v *= k, res++) {
    for (int i = 0; i < n; i += 1) {
      for (int j = i + 1; j < n; j += 1) {
        if (i / v % k != j / v % k) {
          c[i][j] = res;
        }
      }
    }
  }
  cout << res << '\n';
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) cout << c[i][j] + 1 << ' ';
  cout << '\n';
}