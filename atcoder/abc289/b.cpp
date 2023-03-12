#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0, x; i < m; i++) {
    cin >> x, x--, a[x] = 1;
  }
  for (int i = 0, j; i < n; i = j + 1) {
    for (j = i; j < n && a[j];) j++;
    for (int k = j; k >= i; k--) {
      cout << k + 1 << " ";
    }
  }
  cout << "\n";
}
