#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, x, y;
    cin >> x >> y >> n;
    vector<int> b(n - 1);
    int sum = 0;
    for (int i = n - 2, t = 1; i >= 0; i--) sum += t, b[i] = t++;
    int remain = (y - x) - sum;
    if (remain < 0) {
      cout << "-1\n";
      continue;
    }
    b[0] += remain;
    int cur = x;
    for (int i = 0; i < n; i++) {
      cout << cur << " ";
      if (i < n - 1) cur += b[i];
    }
    cout << "\n";
  }
}
