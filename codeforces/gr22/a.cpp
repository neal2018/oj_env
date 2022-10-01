#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    if (accumulate(a.begin(), a.end(), 0) > n / 2) {
      for (auto& x : a) x ^= 1;
    }
    int one = accumulate(a.begin(), a.end(), 0);
    int zero = n - one;
    if (one == zero) {
      ll res = accumulate(b.begin(), b.end(), 0ll) * 2;
      res -= *min_element(b.begin(), b.end());
      cout << res << "\n";
    } else {
      vector<int> one_b, zero_b;
      for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
          one_b.push_back(b[i]);
        } else {
          zero_b.push_back(b[i]);
        }
      }
      ll res = accumulate(zero_b.begin(), zero_b.end(), 0ll) * 2;
      sort(one_b.begin(), one_b.end(), greater());
      for (int i = 0; i < one_b.size(); i++) {
        if (i < zero_b.size()) {
          res += 2 * one_b[i];
        } else {
          res += one_b[i];
        }
      }
      cout << res << "\n";
    }
  }
}
