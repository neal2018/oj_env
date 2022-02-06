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
    cin >> n;
    int x = 0;
    while ((1 << (x + 1)) < n) x++;
    int cut = 1 << x;
    for (int i = 1; i < cut; i++) {
      cout << i << " ";
    }
    cout << 0 << " " << cut << " ";
    for (int i = cut + 1; i < n; i++) {
      cout << i << " ";
    }
    cout << "\n";
  }
}