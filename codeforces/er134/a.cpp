#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    set<char> st;
    for (int i = 0; i < 4; i++) {
      char c;
      cin >> c;
      st.insert(c);
    }
    cout << (st.size() - 1) << "\n";
  }
}
