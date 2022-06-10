#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " " << n / 3 + 1 << " " << n / 3 - 1 << "\n";
    } else if (n % 3 == 1) {
      int t = n / 3 - 1;
      cout << t + 1 << " " << t + 3 << " " << t << "\n";
    } else {
      int t = n / 3 - 1;
      cout << t + 2 << " " << t + 3 << " " << t << "\n";
    }
  }
}
