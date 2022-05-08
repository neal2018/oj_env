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
    int cnt = 0;
    for (auto& x : a) cin >> x, cnt += (x < 0), x = abs(x);
    for (int i = 0; i < cnt; i++) {
      a[i] = -a[i];
    }
    cout << (is_sorted(a.begin(), a.end()) ? "YES\n" : "NO\n");
  }
}
