#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    for (int i = 1; i < n - 1; i++) {
      ll diff = a[i - 1] - a[i];
      a[i] += diff, a[i + 1] += diff;
    }
    if (n % 2 == 1 || a.end()[-1] >= a.end()[-2]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
