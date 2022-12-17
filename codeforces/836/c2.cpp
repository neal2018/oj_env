#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> res(n);
    iota(res.begin(), res.end(), 1);
    int good = 0;
    auto a = res;
    do {
      if (res[0] != k || res.back() != 1) continue;
      int f = 1;
      for (int i = 0; i < n - 1; i++) {
        if (res[i] % (i + 1) != 0) {
          f = 0;
          break;
        }
      }
      if (f) {
        a = res;
        good = 1;
        break;
      }
    } while (next_permutation(res.begin(), res.end()));
    if (good) {
      for (auto& x : a) cout << x << " ";
      cout << "\n";
    } else {
      cout << "-1\n";
    }
  }
}
