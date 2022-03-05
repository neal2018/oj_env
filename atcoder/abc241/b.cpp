#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  multiset<int> st;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    st.insert(x);
  }
  int f = 1;
  for (int i = 0, x; i < m; i++) {
    cin >> x;
    if (st.find(x) == st.end()) {
      f = 0;
    } else {
      st.erase(st.find(x));
    }
  }
  cout << (f ? "Yes\n" : "No\n");
}
