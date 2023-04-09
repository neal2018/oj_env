#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int l, r;
    cin >> l >> r;
    int res = l, cur = 0;
    for (int i = l; i <= r; i++) {
      string is = to_string(i);
      auto [mini, maxi] = minmax_element(is.begin(), is.end());
      auto diff = *maxi - *mini;
      if (diff >= cur) res = i, cur = diff;
      if (diff == 9) break;
    }
    cout << res << "\n";
  }
}
