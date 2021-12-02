#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  string n;
  cin >> T;
  while (T--) {
    cin >> n;
    if ((n.back() - '0') % 2 == 0) {
      cout << "0\n";
    } else if ((n[0] - '0') % 2 == 0) {
      cout << "1\n";
    } else {
      int f = 0;
      for (auto& c : n)
        if ((c - '0') % 2 == 0) f = 1;
      if (f)
        cout << "2\n";
      else
        cout << "-1\n";
    }
  }
}