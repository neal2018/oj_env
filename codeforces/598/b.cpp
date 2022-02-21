#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    set<int> st;
    vector<int> res;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
      if (st.count(i)) continue;
      if (a[cur] == i) {
        res.push_back(i);
        cur++;
        continue;
      }
      if (cur == n - 1) {
        res.push_back(a[cur]);
        continue;
      }
      int nex = 0;
      for (int j = cur; j < n; j++) {
        st.insert(a[j]);
        if (a[j] == i) {
          nex = j;
          break;
        }
      }
      res.push_back(i);
      for (int j = cur; j < nex - 1; j++) {
        res.push_back(a[j]);
      }
      a[nex] = a[nex - 1];
      st.erase(a[nex]);
      cur = nex;
    }
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}
