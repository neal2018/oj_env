#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    set<string> st;
    for (int i = 0; i < int(s.size()) - 1; i++) {
      st.insert(s.substr(i, 2));
    }
    cout << st.size() << "\n";
  }
}
