#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (; T--;) {
    int n, sum = 0;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      sum += x;
    }
    if (sum % n == 0) {
      cout << "0\n";
    } else {
      cout << "1\n";
    }
  }
}