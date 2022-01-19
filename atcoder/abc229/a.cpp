#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s1, s2;
  cin >> s1 >> s2;
  if (s1 == "##" || s2 == "##" || (s1[0] == '#' && s2[0] == '#') ||
      (s1[1] == '#' && s2[1] == '#')) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}