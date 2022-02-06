#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (; T--;) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    if (k == 0) {
      cout << 1 << "\n";
    } else {
      auto t = s;
      reverse(t.begin(), t.end());
      if (t == s) {
        cout << 1 << "\n";
      } else {
        cout << 2 << "\n";
      }
    }
  }
}