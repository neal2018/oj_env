#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    // remain = a1^2 + an^2 - 2*a1*an - a1 - an
    // sum = k^2
    // an - a1 = k, k >= n-1
    // n*a1 + [0...k] = k^2
    // [0...k] = k*k - n*a1
    // mini = 0 + 1 + 2 + ... + n-2 + k = (n-1)*(n-2)/2 + k
    // maxi = k + k-1 + ... + k-(n-2) + 0 = (2*k-n+2)*(n-1)/2
    // k*k - n*a1 >= (n-1)*(n-2)/2 + k
    // k*k - ((n-1)*(n-2)/2 + k) >= n*a1
    ll n;
    cin >> n;
    for (ll k = n - 1; k * k <= 4e14; k++) {
      ll mini = (n - 1) * (n - 2) / 2 + k;
      ll a1 = (k * k - mini) / n;
      if (a1 <= 0) continue;
      ll maxi = (2 * k - n + 2) * (n - 1) / 2;
      ll cur = k * k - n * a1;
      if (cur > maxi) continue;
      ll need = cur - mini;
      vector<ll> cnt(n);
      for (ll i = n - 2; i > 0 && need; i--) {
        ll cut = need / i;
        cnt[i] = cut;
        need -= cut * i;
      }
      vector<ll> res(n, a1);
      res[n - 1] = a1 + k;
      ll offset = 0;
      for (int i = 1; i < n - 1; i++) {
        offset += cnt[n - i - 1];
        res[i] = a1 + offset + i;
      }
      for (auto& x : res) cout << x << " ";
      cout << "\n";
      break;
    }
  }
}
