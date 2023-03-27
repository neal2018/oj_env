#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (auto& v : a) {
      int m;
      cin >> m;
      v.resize(m);
      for (auto& x : v) cin >> x;
    }
    vector<int> res(n);
    set<int> st;
    for (int i = n - 1; i >= 0; i--) {
      for (auto& x : a[i]) {
        if (st.count(x) == 0) {
          res[i] = x;
          st.insert(x);
        }
      }
    }
    if (find(res.begin(), res.end(), 0) != res.end()) {
      cout << "-1\n";
    } else {
      for (auto& x : res) {
        cout << x << " ";
      }
      cout << "\n";
    }
  }
}
