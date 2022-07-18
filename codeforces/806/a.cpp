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
    for (auto& x : s) x = char(tolower(x));
    cout << (s == "yes" ? "YES\n" : "NO\n");
  }
}
