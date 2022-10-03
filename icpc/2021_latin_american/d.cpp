#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  multiset<ll> st;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    st.insert(x);
  }
  int cnt = 0;
  while (st.size()) {
    int t = int(st.size());
    if (t >= 2) {
      auto x = *st.begin();
      auto y = *next(st.begin());
      if (x == y) {
        st.extract(x);
        st.extract(x);
        st.insert(x + 1);
        continue;
      }
    }
    st.erase(st.begin());
    cnt++;
    if (cnt == 2) break;
  }
  if (st.size() == 0 && (cnt == 2 || (cnt == 1 && n >= 2))) {
    cout << "Y\n";
  } else {
    cout << "N\n";
  }
}
