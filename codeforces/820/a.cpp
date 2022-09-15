#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    int cost1 = abs(a - 1);
    int cost2 = abs(b - c) + abs(c - 1);
    if (cost1 < cost2) {
      cout << "1\n";
    } else if (cost1 > cost2) {
      cout << "2\n";
    } else {
      cout << "3\n";
    }
  }
}
