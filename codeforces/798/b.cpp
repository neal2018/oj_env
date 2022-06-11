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
    vector<ll> a(n);
    for (auto& x : a) cin >> x, x--;
    if (n == 1) {
      cout << "-1\n";
      continue;
    }
    vector<ll> res(n);
    set<ll> avail;
    for (auto i : views::iota(0, n)) avail.insert(i);
    for (int i = 0; i < n; i++) {
      auto t = *avail.begin();
      if (t == a[i]) {
        if (avail.size() > 1) {
          t = *(++avail.begin());
        }
      }
      avail.erase(t);
      res[i] = t;
    }
    if (res.back() == a.back()) {
      swap(res[n - 1], res[n - 2]);
    }
    for (auto& x : res) cout << x + 1 << " ";
    cout << "\n";
  }
}
