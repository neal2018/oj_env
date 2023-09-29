#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  vector<int> o(n);
  iota(o.begin(), o.end(), 0);
  do {
    if ([&] {
          for (int i = 0; i < n - 1; i++) {
            auto cur = a[o[i]];
            auto nex = a[o[i + 1]];
            int diff = 0;
            for (int t = 0; t < m; t++) {
              if (cur[t] != nex[t]) diff++;
            }
            if (diff != 1) return false;
          }
          return true;
        }()) {
      cout << "Yes\n";
      return 0;
    }
  } while (next_permutation(o.begin(), o.end()));
  cout << "No\n";
}
