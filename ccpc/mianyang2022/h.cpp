#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  cout << 2 * n - 1 << "\n";
  for (int i = 1; i <= 2 * n - 1; i++) {
    cout << i << " " << i << "\n";
  }
}
