#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n >> m;
    set<ll> st;
    for (ll i = 0, k; i < n; i++) {
      cin >> k;
      st.insert(k);
    }
    vector<ll> v(st.begin(), st.end());
    for (int i = 0; i < m; i++) {
      ll a, b, c;
      cin >> a >> b >> c;
      if (c <= 0) {
        cout << "NO\n";
        continue;
      }
      ll k_id = [&] {
        auto check = [&](int mid) {
          ll kk = v[mid];
          if (kk > b) return true;
          if ((kk - b) * (kk - b) < 4 * a * c) return true;
          return false;
        };
        int l = 0, r = int(v.size());
        while (l < r) {
          int mid = (l + r) / 2;
          if (check(mid)) {
            r = mid;
          } else {
            l = mid + 1;
          }
        }
        return r;
      }();
      if (k_id == v.size()) {
        cout << "NO\n";
        continue;
      }
      ll kk = v[k_id];
      if ((kk < b) || (kk - b) * (kk - b) < 4 * a * c) {
        cout << "YES\n";
        cout << kk << "\n";
      } else {
        cout << "NO\n";
      }
    }
    cout << "\n";
  }
}
