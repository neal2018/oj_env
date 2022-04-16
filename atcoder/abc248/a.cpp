#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  string s;
  cin >> s;
  int a = 0;
  for (int i = 0; i < 10; i++) a ^= i;
  for (auto& c : s) a ^= (c - '0');
  cout << a << "\n";
}
