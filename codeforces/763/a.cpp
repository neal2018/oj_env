#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (; T--;) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    rb--, cb--, rd--, cd--;
    if (rb > rd) {
      rd = 2 * n - rd - 2;
    }
    if (cb > cd) {
      cd = 2 * m - cd - 2;
    }
    cout << min(cd - cb, rd - rb) << "\n";
  }
}