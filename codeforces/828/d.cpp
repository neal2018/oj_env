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
    for (auto& x : a) cin >> x;
    auto get = [&](int i) {
      int x = 0;
      while (i % 2 == 0) x++, i /= 2;
      return x;
    };
    vector<int> avail(n);
    ll need = n;
    for (int i = 0; i < n; i++) {
      avail[i] = get(i + 1);
      need -= get(a[i]);
    }
    sort(avail.begin(), avail.end());
    int res = 0;
    while (need > 0 && avail.size()) {
      need -= avail.back();
      avail.pop_back();
      res++;
    }
    if (need > 0) {
      cout << "-1\n";
    } else {
      cout << res << "\n";
    }
  }
}
