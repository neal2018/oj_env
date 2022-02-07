#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    if (k == 0 || s == string(s.rbegin(), s.rend())) {
      cout << 1 << "\n";
    } else {
      cout << 2 << "\n";
    }
  }
}
