#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    string s;
    cin >> n >> k >> s;
    map<char, char> mp;
    string t(n, '?');
    for (int i = 0; i < n; i++) {
      if (mp.count(s[i]) == 0) {
        char c = s[i];
        vector<char> seen{c};
        while (k > 0 && c > 'a') {
          k--, c--;
          seen.push_back(c);
          if (mp.count(c)) c = mp[c];
        }
        for (auto& cc : seen) mp[cc] = c;
      }
      t[i] = mp[s[i]];
    }
    cout << t << "\n";
  }
}
