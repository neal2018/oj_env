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
    char c;
    cin >> c;
    ll n = s.size(), f = 0;
    for (int i = 0; i < n; i += 2) {
      if (s[i] == c) f = 1;
    }
    cout << (f ? "YES\n" : "NO\n");
  }
}
