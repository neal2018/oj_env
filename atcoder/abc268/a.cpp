#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<int> a(5);
  for (auto& x : a) cin >> x;
  cout << set(a.begin(), a.end()).size() << "\n";
}
