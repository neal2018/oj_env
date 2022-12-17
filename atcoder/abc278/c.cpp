#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  map<int, set<int>> mp;
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y, x--, y--;
    if (t == 1) {
      mp[x].insert(y);
    } else if (t == 2) {
      mp[x].erase(y);
    } else {
      if (mp[x].count(y) && mp[y].count(x)) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
  }
}
