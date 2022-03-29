#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    int f = 0;
    if (a[n - 1] <= d) f = 1;
    if (a[0] + a[1] <= d) f = 1;
    cout << (f ? "YES\n" : "NO\n");
  }
}
