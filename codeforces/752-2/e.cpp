#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
constexpr int MOD = 998244353, maxi = 1e5 + 10;

int f[maxi], g[maxi];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, v, t;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    ll res = 0;
    for (int i = n - 2; i >= 0; i--) {
      f[a[i + 1]]++;
      for (int l = 1, r; l <= a[i + 1]; l = r + 1) {
        v = a[i + 1] / l;
        r = a[i + 1] / v;
        t = (a[i] + v - 1) / v;
        (res += 1ll * f[v] * (i + 1) % MOD * (t - 1) % MOD) %= MOD;
        (g[a[i] / t] += f[v]) %= MOD;
        f[v] = 0;
      }
      for (int l = 1, r; l <= a[i]; l = r + 1) {
        v = a[i] / l;
        r = a[i] / v;
        f[v] = g[v], g[v] = 0;
      }
    }
    for (int l = 1, r; l <= a[0]; l = r + 1) {
      v = a[0] / l;
      r = a[0] / v;
      f[v] = 0;
    }
    cout << res << '\n';
  }
}