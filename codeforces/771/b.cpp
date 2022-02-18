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
    vector<int> a(n), even, odd;
    for (auto& x : a) cin >> x;
    for (auto& x : a) ((x & 1) ? odd : even).push_back(x);
    if (is_sorted(odd.begin(), odd.end()) && is_sorted(even.begin(), even.end())) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
