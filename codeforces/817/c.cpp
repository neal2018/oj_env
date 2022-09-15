#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<string>> a(3, vector<string>(n));
    map<string, int> mp;
    for (auto& r : a) {
      for (auto& x : r) cin >> x, mp[x]++;
    }
    for (auto& r : a) {
      int res = 0;
      for (auto& x : r) {
        res += (mp[x] == 1 ? 3 : (mp[x] == 2 ? 1 : 0));
      }
      cout << res << " ";
    }
    cout << "\n";
  }
}
