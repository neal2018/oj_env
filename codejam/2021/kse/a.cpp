#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define LOCAL

int main() {
#ifdef LOCAL
  ifstream cin("/Users/neallai/Projects/oj_env/input.txt");
  ofstream cout("/Users/neallai/Projects/oj_env/output.txt");
#endif  // LOCAL
  int T;
  string s;
  cin >> T;
  for (int TT = 1; TT <= T; TT++) {
    cout << "Case #" << TT << ": ";
    cin >> s;
    int n = s.size();
    map<int, int> mp;
    for (auto& c : s) mp[c]++;
    int maxi = 0;
    for (auto& it : mp) maxi = max(maxi, it.second);
    if (maxi > (n) / 2) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    string res = s;
    for (int i = 0; i < n; i++) {
      auto it = mp.begin();
      while (it->first == res[i]) {
        it++;
      }
      if (it == mp.end()) {
        int mark = 0;
        for (int j = i - 1; j > 0; j--) {
          if (res[j] != res[i] && s[j] != res[i]) {
            mark = j;
            break;
          }
        }
        swap(res[i], res[mark]);
        mp[res[mark]]--;
        if (mp[res[mark]] == 0) {
          mp.erase(res[mark]);
        }
        continue;
      }
      res[i] = it->first;
      it->second--;
      if (it->second == 0) {
        mp.erase(it);
      }
    }
    cout << res << endl;
  }
}
