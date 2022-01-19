#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (; T--;) {
    int n, l;
    cin >> n >> l;
    vector<int> a(n), b(l);
    for (auto& x : a) cin >> x;
    for (int i = 0; i < l; i++) {
      for (auto& x : a) {
        if ((x & (1 << i))) b[i]++;
      }
    }
    int res = 0;
    for (int i = l - 1; i >= 0; i--) {
      res = res * 2;
      if (b[i] > n / 2) res++;
    }
    cout << res << "\n";
  }
}