#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    ll total = n * (n + 1) / 2, f = 1;
    if (sum % total) f = 0;
    ll s = sum / total;
    vector<ll> res(n);
    for (int i = 0; i < n && f; i++) {
      ll diff = a[i] - a[(i - 1 + n) % n];
      ll remain = diff - s;
      remain = -remain;
      if (remain <= 0 || remain % n) {
        f = 0;
      } else {
        res[i] = remain / n;
      }
    }
    if (f) {
      cout << "YES\n";
      for (auto& x : res) cout << x << " ";
      cout << "\n";
    } else {
      cout << "NO\n";
    }
  }
}
