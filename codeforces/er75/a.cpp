#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    set<char> st;
    ll n = s.size();
    for (int i = 0, j; i < n; i = j) {
      for (j = i; j < n && s[i] == s[j];) j++;
      if ((j - i) & 1) st.insert(s[i]);
    }
    for (auto& c : st) cout << c;
    cout << "\n";
  }
}
