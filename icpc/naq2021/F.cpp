#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> m >> n;
  vector<ll> a(m);
  for (auto& x : a) cin >> x;
  ll sum = accumulate(a.begin(), a.end(), 0ll);
  for (ll _ = 0; _ < n; _++) {
    ll need;
    cin >> need;
    need = sum - need;
    ll l = 0, cur = 0, f = 0;
    if (need >= 0) {
      for (ll r = 0; r < m; r++) {
        cur += a[r];
        while (cur > need) {
          cur -= a[l];
          l++;
        }
        if (cur == need) {
          f = 1;
          break;
        }
      }
    }
    if (f) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}