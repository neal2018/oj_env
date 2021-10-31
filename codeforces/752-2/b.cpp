#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
const ll MOD = 1e9 + 7;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    if (n % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    int f = 1;
    for (int i = 0; i < n - 1; i++) {
      if (a[i + 1] <= a[i]) {
        f = 0;
        break;
      }
    }
    if (f) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}