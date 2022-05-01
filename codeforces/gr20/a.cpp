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
    ll cnt = 0;
    vector<ll> a(n);
    for (auto& x : a) cin >> x, cnt += x - 1;
    cout << ((cnt & 1) ? "errorgorn\n" : "maomao90\n");
  }
}
