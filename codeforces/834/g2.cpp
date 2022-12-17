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
    vector<int> b(n / 2);
    set<int> avail;
    for (int i = 0; i < n; i++) avail.insert(i);
    for (auto &x : b) cin >> x, x--, avail.erase(x);

    vector<int> res(n);
    if ([&] {
          if (avail.size() != n / 2) return false;
          for (int i = n / 2 - 1; i >= 0; i--) {
            auto it = avail.upper_bound(b[i]);
            if (it == avail.begin()) return false;
            res[2 * i] = *--it, res[2 * i + 1] = b[i];
            avail.erase(it);
          }
          return true;
        }()) {
      for (auto &x : res) cout << x + 1 << " ";
      cout << "\n";
    } else {
      cout << "-1\n";
    }
  }
}
