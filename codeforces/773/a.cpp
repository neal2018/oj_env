#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    multiset<ll> st;
    for (auto& x : a) {
      if (x % k == 0 && st.find(x / k) != st.end()) {
        st.erase(st.find(x / k));
      } else if (st.find(x * k) != st.end()) {
        st.erase(st.find(x * k));
      } else {
        st.insert(x);
      }
    }
    cout << st.size() << "\n";
  }
}
