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
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    for (int i = 0; i < n; i++) {
      cout << *lower_bound(b.begin(), b.end(), a[i]) - a[i] << " ";
    }
    cout << "\n";
    vector<int> larger(n), pre(n + 1);
    for (int i = 1; i < n; i++) {
      larger[i] = (a[i] > b[i - 1]);
    }
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + larger[i];
    for (int i = 0; i < n; i++) {
      auto check = [&](int mid) {
        // a[i]>b[i-1] for i in (i, n)
        int cur = pre[mid + 1] - pre[i + 1];
        return cur == 0;
      };
      int l = i, r = n - 1;
      while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      cout << b[l] - a[i] << " ";
    }
    cout << "\n";
  }
}
