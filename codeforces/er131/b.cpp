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
    set<int> st;
    for (int i = 1; i <= n; i++) {
      st.insert(i);
    }
    cout << "2\n";
    int pre = -1;
    while (st.size()) {
      if (st.count(2 * pre)) {
        cout << 2 * pre << " ";
        st.erase(2 * pre);
        pre = 2 * pre;
      } else {
        cout << *st.begin() << " ";
        pre = *st.begin();
        st.erase(st.begin());
      }
    }
    cout << "\n";
  }
}
