#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, m;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    if (n == 1 && m == 1)
      cout << "0\n";
    else if (n == 1 || m == 1)
      cout << "1\n";
    else
      cout << "2\n";
  }
}