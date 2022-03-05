#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<int> a(10);
  for (auto& x : a) cin >> x;
  cout << a[a[a[0]]] << "\n";
}
