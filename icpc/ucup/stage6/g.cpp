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
    map<string, int> st;
    int n = int(s.size());
    string res = "";
    int pos = n;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        auto t = s.substr(i, j - i + 1);
        if (st.count(t) && (res.size() < t.size() || (res.size() == t.size() && pos > st[t]))) {
          res = t, pos = st[t];
        }
      }
      for (int j = 0; j <= i; j++) {
        auto t = s.substr(j, i - j + 1);
        st[t] = j;
      }
    }
    cout << res << "\n";
  }
}
