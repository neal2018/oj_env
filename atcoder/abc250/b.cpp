#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, a, b;
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    for (int ii = 0; ii < a; ii++) {
      for (int j = 0; j < n; j++) {
        for (int jj = 0; jj < b; jj++) {
          cout << ((i + j) % 2 == 0 ? '.' : '#');
        }
      }
      cout << "\n";
    }
  }
}
