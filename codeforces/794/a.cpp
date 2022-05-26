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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    int f = 0;
    for (auto& x : a) {
      if (x * n == sum) f = 1;
    }
    cout << (f ? "YES\n" : "NO\n");
  }
}
