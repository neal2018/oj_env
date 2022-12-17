#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q;
  cin >> q;
  set<ll> st;
  map<ll, ll> res;
  while (q--) {
    char c;
    ll x;
    cin >> c >> x;
    if (c == '+') {
      st.insert(x);
    } else {
      auto& t = res[x];
      if (t == 0) t = x;
      while (st.count(t)) {
        t += x;
      }
      cout << t << "\n";
    }
  }
}
