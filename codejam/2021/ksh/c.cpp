#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  string s;
  cin >> T;
  // auto solve = [&] {
  // };
  for (ll ttt = 1; ttt <= T; ttt++) {
    cin >> n >> s;
    string ns = "";
    while (true) {
      string prev = s;
      for (int x = 0; x < 10; x++) {
        ns = "";
        for (int i = 0; i < (int)s.size(); i++) {
          if (i != (int)s.size() - 1 && s[i] == x + '0' && s[i + 1] == (x + 1) % 10 + '0') {
            ns.push_back((char)((x + 2) % 10 + '0'));
            i++;
          } else {
            ns.push_back(s[i]);
          }
        }
        swap(s, ns);
      }
      if (prev == s) break;
    }
    cout << "Case #" << ttt << ": " << s << '\n';
  }
  return 0;
}