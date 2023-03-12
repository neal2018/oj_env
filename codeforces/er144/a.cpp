#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    string t;
    while (t.size() < n) {
      t += "FBFFBFFB";
    }
    t += "FBFFBFFB";
    if (t.find(s) != string::npos) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
