#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, p;
  cin >> n >> m >> p;
  if (n < m) {
    cout << "0\n";
  } else {
    cout << 1 + (n - m) / p << "\n";
  }
}
