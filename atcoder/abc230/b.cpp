#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string base = "oxx", t, s;
  for (int i = 0; i < 20; i++) t += base;
  cin >> s;
  if (t.find(s) != string::npos) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}