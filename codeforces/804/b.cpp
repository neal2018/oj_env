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
    for (int i = 0; i < n / 2; i++) {
      for (auto f : {int(i % 2 == 0), i % 2}) {
        for (int j = 0; j < m; j++) {
          cout << f << " ";
          if (j % 2 == 0) f = !f;
        }
        cout << "\n";
      }
    }
  }
}
