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
    for (auto& x : a) cin >> x;
    multiset<ll> st(a.begin(), a.end());
    ll f = 1;
    ll total = accumulate(a.begin(), a.end(), 0ll);
    multiset<ll> cur{total};
    while (cur.size() && cur.size() <= st.size()) {
      auto x = *cur.begin();
      cur.erase(cur.begin());
      if (st.find(x) != st.end()) {
        st.erase(st.find(x));
      } else {
        cur.insert(x / 2);
        cur.insert((x + 1) / 2);
      }
    }
    f = (st.size() == 0);
    cout << (f ? "YES\n" : "NO\n");
  }
}
