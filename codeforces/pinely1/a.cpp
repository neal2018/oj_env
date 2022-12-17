#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (n == a && n == b) {
      cout << "Yes\n";
      continue;
    }
    if (a + b < n - 1) {
      cout << "Yes\n";
      continue;
    }
    cout << "No\n";
  }
}
