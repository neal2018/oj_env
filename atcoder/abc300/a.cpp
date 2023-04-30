#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> c(n);
  for (auto& x : c) cin >> x;
  for (int i = 0; i < n; i++) {
    if (c[i] == a + b) {
      cout << i + 1 << "\n";
    }
  }
}
