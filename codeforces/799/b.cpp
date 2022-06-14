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
    map<int, int> mp;
    for (int x; [[maybe_unused]] auto i : views::iota(0, n)) {
      cin >> x, mp[x]++;
    }
    int odd = 0, even = 0;
    for (auto& [k, v] : mp) {
      ((v & 1) ? odd : even)++;
    }
    cout << odd + (even / 2 * 2) << "\n";
  }
}
