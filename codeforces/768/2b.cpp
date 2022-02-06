#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (; T--;) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    ll need = 0, cur = n - 1;
    while (cur > 0) {
      if (a[cur - 1] == a.back()) {
        cur--;
      } else {
        cur = n - (n - cur) * 2;
        need++;
      }
    }
    cout << need << "\n";
  }
}