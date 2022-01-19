#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll k;
  cin >> k;
  string s;
  while (k) {
    if (k & 1)
      s += '2';
    else
      s += '0';
    k /= 2;
  }
  reverse(s.begin(), s.end());
  cout << s << "\n";
}