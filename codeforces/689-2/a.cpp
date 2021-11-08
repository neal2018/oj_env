#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, k;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = 0; i < n / 3; i++) cout << "abc";
    if (n % 3 == 1)
      cout << "a\n";
    else if (n % 3 == 2)
      cout << "ab\n";
    else
      cout << '\n';
  }
}