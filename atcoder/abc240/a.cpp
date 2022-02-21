#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int a, b;
  cin >> a >> b, a--, b--;
  cout << (((a + 1) % 10 == b || (a + 9) % 10 == b) ? "Yes\n" : "No\n");
}
