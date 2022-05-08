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
    vector<ll> a(3);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    if (a[0] + a[1] + 1 >= a[2]) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
