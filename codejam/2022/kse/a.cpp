#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    multiset st(a.begin(), a.end());
    for (auto& x : a) {
      auto it = --st.upper_bound(2 * x);
      if (*it == x) {
        if (it == st.begin()) {
          cout << "-1 ";
        } else {
          cout << *prev(it) << " ";
        }
      } else {
        cout << *it << " ";
      }
    }
    cout << "\n";
  }
}
