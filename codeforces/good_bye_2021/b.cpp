#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  auto f = [&]() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int index = n - 1;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] < s[i + 1]) {
        index = i;
        break;
      }
    }
    int same = (n == 1 || s[0] == s[1]);
    if (same) index = 0;
    for (int i = 0; i <= index; i++) cout << s[i];
    for (int i = index; i >= 0; i--) cout << s[i];
    cout << "\n";
  };
  while (T--) f();
}