#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    multiset<int> st;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int dis = 0;
        dis = max(dis, abs(i) + abs(j));
        dis = max(dis, abs(n - i - 1) + abs(j));
        dis = max(dis, abs(i) + abs(m - j - 1));
        dis = max(dis, abs(n - i - 1) + abs(m - j - 1));
        st.insert(dis);
      }
    }
    for (int i = 0; i < n * m; i++) {
      cout << *st.begin() << " ";
      st.erase(st.begin());
    }
    cout << "\n";
  }
}