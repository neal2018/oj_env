#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> s;
    mp[s]++;
  }
  string ans = s;
  for (auto& [k, v] : mp) {
    if (v > mp[ans]) ans = k;
  }
  cout << ans << '\n';
}