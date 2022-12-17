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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    auto st = set(a.begin(), a.end());
    if (st.size() != n) {
      cout << "NO\n";
      continue;
    }
    for (int i = 1; i <= a.back(); i++) {
      if (st.count(i) == 0) {
        m -= i;
      }
    }
    int cur = a.back() + 1;
    while (m > 0) {
      m -= cur;
      cur++;
    }
    if (m == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
