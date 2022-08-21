#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    ll sum_q = s - b * k;
    if (sum_q < 0 || sum_q > n * (k - 1)) {
      cout << "-1\n";
    } else {
      vector<ll> a(n);
      for (int i = 0; i < n; i++) {
        ll minus = min(sum_q, k - 1);
        a[i] += minus, sum_q -= minus;
      }
      a.back() += b * k;
      for (auto& x : a) cout << x << " ";
      cout << "\n";
    }
  }
}
