#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<string> s(n - 2);
    for (auto& x : s) cin >> x;
    int remain = 2;
    cout << s[0][0];
    for (int i = 1; i < n - 2; i++) {
      if (s[i - 1][1] == s[i][0]) {
        cout << s[i][0];
      } else {
        cout << s[i - 1][1] << s[i][0];
        remain = 1;
      }
    }
    for (int i = 0; i < remain; i++) cout << s.back()[1];
    cout << '\n';
  }
}