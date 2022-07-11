#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    map<int, int> first, last;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      if (!first.count(x)) first[x] = i;
      last[x] = i;
    }
    while (k--) {
      int x, y;
      cin >> x >> y;
      cout << ((first.count(x) && last.count(y) && first[x] <= last[y]) ? "YES\n" : "NO\n");
    }
  }
}
