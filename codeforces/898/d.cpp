#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int r = 0;
    int res = 0;
    for (auto& x : s) {
      if (r > 0) {
        r--;
      } else {
        if (x == 'B') {
          r = k - 1;
          res++;
        }
      }
    }
    cout << res << "\n";
  }
}
