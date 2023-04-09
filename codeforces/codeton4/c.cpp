#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, c, d;
    cin >> n >> d >> c;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    ll res = n * d + c;
    set<ll> st;
    for (int i = 0; i < n; i++) {
      st.insert(a[i]);
      res = min(res, n * d - (ll(st.size())) * d + (a[i] - ll(st.size())) * c);
    }
    cout << res << "\n";
  }
}
