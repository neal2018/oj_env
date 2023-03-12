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
    multiset<ll> st;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == 0) {
        cnt++;
      } else {
        st.insert(a[i]);
        while (st.size() > cnt) {
          st.erase(st.begin());
        }
      }
    }
    ll res = accumulate(st.begin(), st.end(), 0ll);
    cout << res << "\n";
  }
}
