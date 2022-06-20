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
    vector<int> a(n);
    map<int, int> mp;
    for (auto& x : a) cin >> x, x %= 10, mp[x]++;
    vector<int> b;
    for (auto& [k, v] : mp) {
      for ([[maybe_unused]] auto i : views::iota(0, min(3, v))) {
        b.push_back(k);
      }
    }
    int sz = int(b.size());
    if ([&] {
          for (auto i : views::iota(0, sz)) {
            for (auto j : views::iota(i + 1, sz)) {
              for (auto k : views::iota(j + 1, sz)) {
                if ((b[i] + b[j] + b[k]) % 10 == 3) {
                  return true;
                }
              }
            }
          }
          return false;
        }()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
