#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    string res(n, '0');
    for (int now = 0; auto i : views::iota(0, n) | views::reverse) {
      if (a[i] > now) {
        if (q > now) now++, res[i] = '1';
      } else {
        res[i] = '1';
      }
    }
    cout << res << "\n";
  }
}
