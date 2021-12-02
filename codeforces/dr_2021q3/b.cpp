#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q;
  string s;
  cin >> n >> q >> s;
  set<int> st;
  for (int i = 0; i < n - 2; i++)
    if (s.substr(i, 3) == "abc") st.insert(i);
  char c;
  for (int pos; q--;) {
    cin >> pos >> c, pos--;
    if (c != s[pos]) {
      if (pos >= 2 && s.substr(pos - 2, 3) == "abc") st.erase(pos - 2);
      if (pos >= 1 && s.substr(pos - 1, 3) == "abc") st.erase(pos - 1);
      if (pos >= 0 && s.substr(pos, 3) == "abc") st.erase(pos);
      s[pos] = c;
      if (pos >= 2 && s.substr(pos - 2, 3) == "abc") st.insert(pos - 2);
      if (pos >= 1 && s.substr(pos - 1, 3) == "abc") st.insert(pos - 1);
      if (pos >= 0 && s.substr(pos, 3) == "abc") st.insert(pos);
    }
    cout << st.size() << '\n';
  }
}