#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    map<int, int> mp;
    for (auto& c : s) mp[c - 'a']++;
    string res;
    for (int i = 0; i < k; i++) {
      int need = n / k;
      int cur = 0, added = 0;
      for (int j = 0; j < need; j++) {
        if (mp[cur] == 0) {
          res += char(cur + 'a');
          added = 1;
          break;
        } else {
          mp[cur]--, cur++;
        }
      }
      if (!added) {
        res += char(cur + 'a');
      }
    }
    cout << res << "\n";
  }
}
