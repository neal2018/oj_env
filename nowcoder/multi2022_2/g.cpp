#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  if (s.size() == 1) {
    cout << s[0] << "\n";
  } else {
    if ([&] {
          for (int i = 0; i < int(s.size()) - 1; i++) {
            if (s[i] != '9') {
              return false;
            }
          }
          return true;
        }()) {
      cout << s << "\n";
    } else {
      cout << string(int(s.size()) - 1, '9') << "\n";
    }
  }
}
