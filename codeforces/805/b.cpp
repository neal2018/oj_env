#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0, j; i < s.size(); i = j) {
      set<char> st;
      for (j = i; j < s.size(); j++) {
        if (st.size() == 3 && st.count(s[j]) == 0) break;
        st.insert(s[j]);
      }
      res++;
    }
    cout << res << "\n";
  }
}
