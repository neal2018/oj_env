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
    vector<int> res(n);
    iota(res.begin(), res.end(), 0);
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
      for (auto& x : res) cout << x + 1 << " ";
      cout << "\n";
      if (i != n - 1) {
        swap(res[i], res[i + 1]);
      }
    }
  }
}
