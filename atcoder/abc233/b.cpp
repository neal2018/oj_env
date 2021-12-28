#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int l, r;
  string s;
  cin >> l >> r >> s;
  reverse(s.begin() + l-1, s.begin() + r);
  cout << s << "\n";
}