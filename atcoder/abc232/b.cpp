#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  char c1 = s[0], c2 = t[0];
  for (auto& c : s) c = (c - c1 + 26) % 26 + 'a';
  for (auto& c : t) c = (c - c2 + 26) % 26 + 'a';
  // cout<<s<<" "<<t<<endl;
  cout << ((s == t) ? ("Yes\n") : ("No\n"));
}