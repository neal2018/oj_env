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
  for (int case_num = 1; case_num <= T; case_num++) {
    cout << "Case #" << case_num << ": ";
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    ll res = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > res) {
        res++;
      }
    }
    cout << res << "\n";
  }
}