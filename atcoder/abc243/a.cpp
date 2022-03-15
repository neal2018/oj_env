#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll v, a, b, c;
  cin >> v >> a >> b >> c;
  v %= (a + b + c);
  if (v < a) {
    cout << "F\n";
  } else if (v < a + b) {
    cout << "M\n";
  } else {
    cout << "T\n";
  }
}
