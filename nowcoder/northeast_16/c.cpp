#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, q;
    cin >> n >> q;
    ll layer = 0, need = 2 * n - 1;
    while (need >= (1ll << layer)) {
      need -= (1ll << layer);
      layer++;
    }
    ll res = 0;
    for (int i = 0; i < layer; i++) {
      res += min(q, (1ll << i));
    }
    if (q <= (1ll << layer) / 2) {
      res += min(q, need / 2);
    } else {
      ll wasted = (1ll << layer) / 2 - need / 2;
      res += min(q - wasted, need);
    }
    cout << res << "\n";
  }
}
 