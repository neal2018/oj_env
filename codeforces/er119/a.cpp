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
    if (count(s.begin(), s.end(), 'N') == 1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}