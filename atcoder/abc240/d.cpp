#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  while (T--) {
    ll a, s;
    cin >> a >> s;
    ll need = s - 2 * a;
    if (need < 0 || (need & (~a)) != need) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
}