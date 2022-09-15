#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k, r, c;
    cin >> n >> k >> r >> c, r--, c--;
    vector res(n, string(n, '.'));
    for (int start = (c + r) % k; start < n; start += k) {
      for (int i = 0; i < n; i++) {
        res[i][(start - i + n) % n] = 'X';
      }
    }
    for (auto& x : res) cout << x << "\n";
  }
}
