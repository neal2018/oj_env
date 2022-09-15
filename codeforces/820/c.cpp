#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    vector<int> res;
    vector count(26, vector<int>());
    for (int i = 0; i < s.size(); i++) {
      count[s[i] - 'a'].push_back(i);
    }
    int inc = (s[0] > s.back() - 1) ? -1 : 1;
    for (int i = s[0] - 'a';; i += inc) {
      for (auto& x : count[i]) res.push_back(x);
      if (i == s.back() - 'a') break;
    }
    cout << abs(s.back() - s[0]) << " " << res.size() << "\n";
    for (auto& x : res) cout << x + 1 << " ";
    cout << "\n";
  }
}
