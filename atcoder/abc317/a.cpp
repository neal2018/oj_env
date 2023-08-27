#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, h, x;
  cin >> n >> h >> x;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (h + t >= x) {
      cout << i + 1 << "\n";
      return 0;
    }
  }
}
