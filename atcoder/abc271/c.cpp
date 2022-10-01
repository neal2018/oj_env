#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  auto check = [&](int mid) {
    multiset st(a.begin(), a.end());
    int need = 0;
    for (int i = 1; i <= mid; i++) {
      if (st.find(i) != st.end()) {
        st.extract(i);
      } else {
        need++;
      }
    }
    return need * 2 <= st.size();
  };
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << "\n";
}
