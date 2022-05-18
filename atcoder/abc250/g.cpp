#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll res = 0;
  multiset<ll> st;
  for (auto& x : a) {
    if (st.size() && *st.begin() < x) {
      res += x - *st.begin();
      st.erase(st.begin());
      st.insert(x);
    }
    st.insert(x);
  }
  cout << res << "\n";
}
