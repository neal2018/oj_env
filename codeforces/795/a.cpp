#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, odd = 0, even = 0;
    cin >> n;
    for (int i = 0, x; i < n; i++) cin >> x, (x & 1 ? odd : even)++;
    cout << min(odd, even) << "\n";
  }
}