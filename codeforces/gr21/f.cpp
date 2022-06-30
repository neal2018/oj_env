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
    vector a(n, vector<string>(n));
    for (auto i : views::iota(0, n)) {
      a[i][i] = string(n, '1');
      for (auto j : views::iota(i + 1, n)) {
        cin >> a[i][j];
        a[j][i] = a[i][j];
      }
    }
    cout << 'a';
  }
}
