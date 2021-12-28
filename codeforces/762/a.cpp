#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  string s;
  for (; T--;) {
    cin >> s;
    if (s.size() % 2 == 0 && s.substr(0, s.size() / 2) == s.substr(s.size() / 2)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}