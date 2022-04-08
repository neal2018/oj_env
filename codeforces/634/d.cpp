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
    constexpr ll n = 9;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    for (auto& x : a) {
      for (auto& c : x) {
        if (c == '2') c = '1';
      }
    }
    for (auto& x : a) cout << x << "\n";
  }
}
