#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int n; T--;) {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int g = -1;
    for (int i = 1; i < n - 1; i++) {
      int diff = abs(a[i] * 2 - a[i + 1] - a[i - 1]);
      if (diff != 0) g = g == -1 ? diff : gcd(g, diff);
    }
    if (g == -1) {
      cout << 0 << '\n';
    } else if (g <= *max_element(a.begin(), a.end())) {
      cout << -1 << '\n';
    } else {
      long long c = a[1] - a[0];
      c = (c % g + g) % g;
      cout << g << ' ' << c << '\n';
    }
  }
}