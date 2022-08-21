#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    if (m > n) swap(n, m);
    if (n == 1 && m == 1) {
      cout << "0\n";
      continue;
    }
    cout << n + m - 2 + m << "\n";
  }
}
