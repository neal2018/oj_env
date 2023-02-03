#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    char c;
    cin >> c;
    cout << ([&] {
      for (auto& x : "codeforces"s) {
        if (c == x) return true;
      }
      return false;
    }()
                 ? "YES\n"
                 : "NO\n");
  }
}
