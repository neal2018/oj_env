#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    set<ll> st;
    for (auto& x : a) cin >> x, st.insert(x);
    ll sz = st.size();
    for (ll k = 1; k <= n; k++) {
      cout << max(sz, k) << " ";
    }
    cout << '\n';
  }
}
