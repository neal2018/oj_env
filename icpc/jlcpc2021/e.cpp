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
    int f = 0;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      if (st.count(x ^ 1)) {
        f = 1;
      }
      st.insert(x);
    }
    cout << (f ? "Yes\n" : "No\n");
  }
}
