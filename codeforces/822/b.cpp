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
    for (int i = 1; i <= n; i++) {
      vector<int> cur(i);
      cur[0] = 1, cur.back() = 1;
      for (auto& x : cur) cout << x << " ";
      cout << "\n";
    }
  }
}
