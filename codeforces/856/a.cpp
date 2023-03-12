#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;  
  set<int> st;
  
  while (T--) {
    int n;
    cin >> n;
    vector<string> a(2 * n - 2);
    for (auto& x : a) cin >> x;
    set<string> st;
    for (auto& s : a) {
      string rev(s.rbegin(), s.rend());
      if (st.count(rev)) {
        st.erase(rev);
      } else {
        st.insert(s);
      }
    }
    cout << (st.size() ? "NO\n" : "YES\n");
  }
}
