#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  auto func = [&]() {
    cin >> n;
    multiset<int> st2;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> a[i], st2.insert(a[i]);
    ranges::sort(a);
    for (int i = 0; i < 2 * n - 1; i++) {
      multiset<int> st = st2;
      vector<pair<int, int>> res;
      int maxi = *st.rbegin();
      st.erase(st.find(maxi));
      int maxi2 = a[i];
      st.erase(st.find(maxi2));
      res.push_back({maxi, maxi2});
      while (st.size()) {
        int top = *st.rbegin(), other = maxi - top;
        st.erase(st.find(*st.rbegin()));
        if (st.find(maxi - top) != st.end()) {
          st.erase(st.find(other)), res.push_back({top, other});
        } else {
          break;
        }
        maxi = top;
      }
      if (st.size() == 0) {
        cout << "YES\n";
        cout << res[0].first + res[0].second << '\n';
        for (auto& [x1, x2] : res) cout << x1 << " " << x2 << '\n';
        return;
      }
    }
    cout << "NO\n";
  };
  while (T--) func();
}