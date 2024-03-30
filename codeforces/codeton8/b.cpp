#include <bits/stdc++.h>
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;

    std::set<int> st;

    int mex = 0;
    int n_mex = 1;

    for (int i = 0; i < n; i++) {
      // if p[i] is mex, then a[i] = n_mex - mex
      if (a[i] == n_mex - mex) {
        std::cout << mex << " ";
        st.insert(mex);
        while (st.contains(mex)) mex++;
        n_mex = mex + 1;
      } else {
        int p = mex - a[i];
        std::cout << p << " ";
        st.insert(p);
      }
      while (st.contains(n_mex)) n_mex++;
    }
    std::cout << "\n";
  }
}
