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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    map<int, int> mp;
    [&]() {
      for (auto& x : a) {
        if (mp.count(x)) {
          cout << "YES\n";
          return;
        }
        mp[x]++;
      }
      cout << "NO\n";
    }();
  }
}
