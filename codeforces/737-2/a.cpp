#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[]) {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, t;
  cin >> t;
  cout << fixed << setprecision(10);
  while (t--) {
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    ll maxi = *max_element(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    cout << maxi + 1.0 * (sum - maxi) / (n - 1) << endl;
  }
  return 0;
}
