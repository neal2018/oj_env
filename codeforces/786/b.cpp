#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  vector<string> a;
  a.reserve(26 * 26);
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (i != j) {
        a.push_back(string(1, 'a' + i) + string(1, 'a' + j));
      }
    }
  }
  sort(a.begin(), a.end());
  map<string, int> mp;
  for (int i = 0; i < a.size(); i++) mp[a[i]] = i;
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    cout << mp[s] + 1 << "\n";
  }
}
