#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    if (is_sorted(a.begin(), a.end())) {
      cout << "0\n";
      continue;
    }
    if (a[n - 2] > a[n - 1] || (a[n - 1] < 0)) {
      cout << "-1\n";
      continue;
    }
    cout << n - 2 << "\n";
    for (int i = 0; i < n - 2; i++) {
      cout << i + 1 << " " << n - 1 << " " << n << "\n";
    }
  }
}
