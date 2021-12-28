#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  while (T--) {
    int n, m, k, last = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
      int pos = last;
      for (int j = 0; j < n % m; j++) {
        cout << (n + m - 1) / m << " ";
        for (int t = 0; t < (n + m - 1) / m; t++) cout << (pos++) % n + 1 << " ";
        last = pos;
        cout << "\n";
      }
      for (int j = n % m; j < m; j++) {
        cout << n / m << " ";
        for (int t = 0; t < n / m; t++) cout << (pos++) % n + 1 << " ";
        cout << "\n";
      }
    }
    cout << "\n";
  }
}
