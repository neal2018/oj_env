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
    string t;
    while (t.size() < s.size() + 10) {
      t += "Yes";
    }
    if (t.find(s) != string::npos) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
