#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    cout << m << " ";
    cout << [&] {
      int cut = (n - m + 1);
      return m / cut + (m % cut != 0);
    }() << "\n";
  }
}
