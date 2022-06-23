#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, cur = 0;
    cin >> n;
    set<array<int, 3>> st;
    st.insert({-n, 0, n - 1});
    vector<int> res(n);
    while (st.size()) {
      auto [len, l, r] = *st.begin();
      st.erase(st.begin());
      int mid = (l + r) / 2;
      res[mid] = ++cur;
      if (l < mid) st.insert({-(mid - l), l, mid - 1});
      if (r > mid) st.insert({-(r - mid), mid + 1, r});
    }
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}
