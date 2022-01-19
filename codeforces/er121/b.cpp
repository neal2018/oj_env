#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  auto f = [&]() {
    string s;
    cin >> s;
    int n = (int)s.size();
    int index = -1;
    for (int i = 0; i < n - 1; i++) {
      int x = s[i] - '0', y = s[i + 1] - '0';
      if (x + y >= 10) {
        index = i;
      }
    }
    if (index != -1) {
      int i = index;
      int x = s[i] - '0', y = s[i + 1] - '0';
      s[i] = ((x + y) / 10) + '0';
      s[i + 1] = ((x + y) % 10) + '0';
    } else {
      int i = 0;
      int x = s[i] - '0', y = s[i + 1] - '0';
      s[i] = ((x + y) / 10) + '0';
      s[i + 1] = ((x + y) % 10) + '0';
    }

    if (s[0] == '0') {
      cout << s.substr(1) << "\n";
    } else {
      cout << s << "\n";
    }
  };
  while (T--) f();
}