#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll res = accumulate(a.begin(), a.end(), 0ll) - (k - 1) * k / 2;
    vector<ll> b(n);
    for (int i = 0; i < n; i++) b[i] = a[i] - (n - 1 - i);
    sort(b.begin(), b.end(), greater<ll>());
    for (int i = 0; i < k; i++) res -= b[i];
    cout << res << "\n";
  }
}
