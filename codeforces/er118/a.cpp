#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  while (T--) {
    int x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    string s1 = to_string(x1), s2 = to_string(x2);
    if (s1.size() + p1 != s2.size() + p2) {
      if (s1.size() + p1 > s2.size() + p2) {
        cout << ">\n";
      } else {
        cout << "<\n";
      }
    } else {
      if (s1.size() < s2.size()) {
        s1 += string(s2.size() - s1.size(), '0');
      } else {
        s2 += string(s1.size() - s2.size(), '0');
      }
      int x11 = stoi(s1), x22 = stoi(s2);
      if (x11 > x22) {
        cout << ">\n";
      } else if (x11 < x22) {
        cout << "<\n";
      } else {
        cout << "=\n";
      }
    }
  }
}