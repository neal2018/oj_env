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
    if (s == "cab" || s == "bca") {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
