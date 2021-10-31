#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  string s;
  cin >> T;
  while (T--) {
    cin >> s;
    int index = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] < s[index]) {
        index = i;
      }
    }
    string s2 = "";
    for (int i = 0; i < s.size(); i++) {
      if (i != index) {
        s2.push_back(s[i]);
      }
    }
    cout << s[index] << " " << s2 << '\n';
  }
}