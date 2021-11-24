#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    if (n % 2 || (!(n & (n - 1)) && __builtin_ctz(n) % 2))
      cout << "Bob\n";
    else
      cout << "Alice\n";
  }
}