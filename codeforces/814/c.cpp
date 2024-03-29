#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector<int> ds;
    for (int i = 2, t = n; i <= t; i++) {
      if (t % i == 0) {
        ds.push_back(n / i);
        while (t % i == 0) t /= i;
      }
    }
    vector<vector<ll>> mp(ds.size());
    multiset<ll> st;
    auto add = [&](int id, int x) {
      mp[id] = vector<ll>(x);
      for (int i = 0; i < n; i++) {
        mp[id][i % x] += a[i];
      }
      for (auto& t : mp[id]) st.insert(t * x);
    };
    for (int i = 0; i < ds.size(); i++) add(i, ds[i]);
    cout << *st.rbegin() << '\n';
    while (q--) {
      int p, x;
      cin >> p >> x, p--;
      for (int i = 0; i < ds.size(); i++) {
        int k = ds[i], id = p % k;
        auto& v = mp[i];
        st.extract(v[id] * k);
        v[id] += -a[p] + x;
        st.insert(v[id] * k);
      }
      a[p] = x;
      cout << *st.rbegin() << "\n";
    }
  }
}
