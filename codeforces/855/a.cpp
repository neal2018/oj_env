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
    for (auto c : s) {
      if (t.size() == 0 || tolower(t.back()) != tolower(c)) {
        t += tolower(c);
      }
    }
    cout << (t == "meow" ? "YES\n" : "NO\n");
  }
}
