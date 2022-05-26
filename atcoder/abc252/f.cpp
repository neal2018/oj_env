#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, len;
  cin >> n >> len;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll sum = accumulate(a.begin(), a.end(), 0ll);
  if (sum < len) {
    n++, a.push_back(len - sum);
  }
  multiset<ll> st(a.begin(), a.end());
  ll res = 0;
  while (st.size() > 1) {
    auto x = *st.begin();
    st.erase(st.begin());
    auto y = *st.begin();
    st.erase(st.begin());
    res += x + y;
    st.insert(x + y);
  }
  cout << res << "\n";
}
