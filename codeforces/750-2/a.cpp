#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, a, b, c;
  cin >> T;
  while (T--) {
    cin >> a >> b >> c;
    ll need = (a + 2 * b + 3 * c) % 2;
    cout << need << '\n';
  }
}