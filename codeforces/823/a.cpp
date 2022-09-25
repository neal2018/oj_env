#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, c;
    cin >> n >> c;
    ll res = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x, mp[x]++;
    }
    for (auto& [k, v] : mp) {
      res += min(c, v);
    }
    cout << res << "\n";
  }
}
