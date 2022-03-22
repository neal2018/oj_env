#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    cout << "9";
    int cur = 8;
    for (int i = 1; i < n; i++) {
      cout << cur;
      cur = (cur + 1) % 10;
    }
    cout << "\n";
  }
}
