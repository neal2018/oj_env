#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  string s, f;
  cin >> T;
  auto solve = [&] {

  };
  for (ll ttt = 1; ttt <= T; ttt++) {
    ll cnt = 0;
    cin >> s >> f;
    set<int> st;
    for (auto& x : f) {
      st.insert(x - 'a');
      st.insert(x - 'a' - 26);
      st.insert(x - 'a' + 26);
    }
    for (auto& x : s) {
      int i = x - 'a', cur = 1e5;
      auto it = st.lower_bound(i);
      if (it != st.end()) {
        cur = min(cur, abs(*it - i));
      }
      if (it != st.begin()) {
        it--;
        cur = min(cur, abs(*it - i));
      }
      cnt += cur;
    }
    cout << "Case #" << ttt << ": " << cnt << '\n';
  }
  return 0;
}