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
    reverse(s.begin(), s.end());
    int last = -1;
    auto inc = [&](int i) {
      while (i < s.size()) {
        if (s[i] < '9') {
          s[i]++;
          return;
        }
        s[i] = '0';
        i++;
      }
      s.push_back('1');
    };
    for (int i = 0; i < s.size(); i++) {
      if ((s[i] - '0') >= 5) {
        inc(i + 1);
        last = i;
      }
    }
    for (int i = 0; i <= last; i++) s[i] = '0';
    reverse(s.begin(), s.end());
    cout << s << "\n";
  }
}
