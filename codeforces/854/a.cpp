#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), res(n, -2);
    for (auto& x : a) cin >> x;
    set<int> st;
    int cur = n - 1;
    for (int i = 0; i < m; i++) {
      auto x = a[i];
      if (!st.count(x)) {
        st.insert(x);
        if (cur >= 0) res[cur] = i, cur--;
      }
    }
    for (auto& x : res) cout << x + 1 << " ";
    cout << "\n";
  }
}
