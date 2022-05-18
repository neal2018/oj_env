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
    ll n, kk;
    cin >> n >> kk;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (auto& x : a) cin >> x, mp[x]++;
    ll pre = -1, res = -1, cnt = 0, l = -1, r = -1, cl = -1, cr = -1;
    for (auto& [k, v] : mp) {
      if (v >= kk) {
        if (pre == -1 || pre == k - 1) {
          cnt++;
          if (pre == -1) {
            cl = k;
          }
          pre = k;
          cr = k;
          if (cnt > res) {
            res = cnt;
            l = cl, r = cr;
          }
        } else {
          cnt = 1;
          pre = cl = cr = k;
          if (cnt > res) {
            res = cnt;
            l = cl, r = cr;
          }
        }
      } else {
        cnt = 0, pre = -1;
      }
    }
    if (res == -1) {
      cout << "-1\n";
    } else {
      cout << l << " " << r << "\n";
    }
  }
}
