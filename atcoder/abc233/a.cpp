#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int x, y;
  cin >> x >> y;
  cout << max(0, (y - x + 9) / 10) << "\n";
}