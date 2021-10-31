#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, a, b, MAXN = 5e5 + 10;
  cin >> T;
  vector<int> x(MAXN);
  for (int i = 1; i < MAXN; i++) {
    x[i] = x[i - 1] ^ i;
  }
  while (T--) {
    cin >> a >> b;
    int temp = x[a - 1];
    int need = temp ^ b;
    if (temp == b) {
      cout << a << '\n';
    } else if (need == a) {
      cout << a + 2 << '\n';
    } else {
      cout << a + 1 << '\n';
    }
  }
}