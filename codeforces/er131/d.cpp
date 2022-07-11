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
    vector<array<int, 3>> a;
    for (int i = 1, x; i <= n; i++) {
      cin >> x;
      int l = i / (x + 1) + 1, r = (x == 0 ? n : (i / x));
      a.push_back({r, l, i - 1});
    }
    sort(a.begin(), a.end());
    set<int> st;
    for (int i = 0; i < n; i++) st.insert(i + 1);
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      auto it = st.lower_bound(a[i][1]);
      res[a[i][2]] = *it;
      st.erase(it);
    }
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}
