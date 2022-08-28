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
    vector<int> a(n), b(n), p1(n), p2(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    int res = 0;
    for (int bit = 29; bit >= 0; bit--) {
      vector<int> o1(n), o2(n);
      iota(o1.begin(), o1.end(), 0);
      sort(o1.begin(), o1.end(), [&](int x, int y) { return p1[x] < p1[y]; });
      iota(o2.begin(), o2.end(), 0);
      sort(o2.begin(), o2.end(), [&](int x, int y) { return p2[x] < p2[y]; });
      if ([&] {
            for (int i = 0, j; i < n; i = j) {
              for (j = i; j < n && p1[o1[i]] == p1[o1[j]];) j++;
              int a1 = 0, b1 = 0;
              for (int k = i; k < j; k++) {
                a1 += ((a[o1[k]] >> bit) & 1);
                b1 += ((b[o2[k]] >> bit) & 1);
              }
              if (a1 + b1 != j - i) return false;
            }
            return true;
          }()) {
        for (int i = 0; i < n; i++) {
          p1[i] = (p1[i] << 1) | ((a[i] >> bit) & 1);
          p2[i] = (p2[i] << 1) | ((~(b[i] >> bit)) & 1);
        }
        res |= (1 << bit);
      }
    }
    cout << res << "\n";
  }
}
